from matplotlib.ticker import (MultipleLocator, FormatStrFormatter,
    AutoMinorLocator)
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rcParams
from matplotlib import rc

import json
import argparse
import math
import os
import sys
import subprocess
from threading import Timer
from termcolor import colored
from collections import ChainMap

def clean_all_bmarks(root_path, bmark_list, result_path):
  os.chdir(result_path)
  os.system("rm -rf *")
  for bmark in bmark_list:
    os.chdir(os.path.join(root_path, bmark))
    make_process = subprocess.Popen(["make", "clean"],
        stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)

    if make_process.wait() != 0:
      print(colored("Clean failed for %s" % bmark, 'red'))

  print("Finish cleaning")
  return 0

def get_time(root_path, bmark, test_types):
  os.chdir(os.path.join(root_path, bmark))
  result = { bmark: {}}
  print(bmark)
  for test_type in test_types:
    f = open(test_type+".time", 'r')
    result[bmark][test_type] = float(f.readline())
    f.close()
  return result

def run_one(path, bmark, test_type):
  os.chdir(path)

  print("Generating %s on %s " % (test_type, bmark))
  with open(test_type+".log", "w") as fd:
    make_process = subprocess.Popen(["make", "run_"+test_type], stdout=fd, stderr=fd)
    timer = Timer(7200, make_process.kill)
    try:
      timer.start()
      stdout, stderr = make_process.communicate()
    finally:
      timer.cancel()

    if make_process.wait() != 0:
      print(colored("%s failed for %s " % (test_type, bmark), 'red'))
      return False
    else:
      print(colored("%s succeeded for %s " % (test_type, bmark), 'green'))
      return True

def run_all(root_path, bmark, tests):
  bmark_path = os.path.join(root_path, bmark)
  status = {}
  for test in tests:
    status[bmark+":"+test] = run_one(bmark_path, bmark, test)
  return status

def Postprocess(perf_dic_acc, perf_dic, bmark_list, run_num):
  for bmark in bmark_list:
    for key in perf_dic[bmark].keys():
      perf_dic[bmark][key] = 0
      for i in range(run_num):
        perf_dic[bmark][key] = perf_dic[bmark][key]+perf_dic_acc[i][bmark][key]/run_num

  #for bmark in bmark_list:
  #  for key in perf_dic[bmark].keys():
  #    if key == 'seq':
  #      continue
  #    else:
  #      perf_dic[bmark][key] = perf_dic[bmark]['seq']/perf_dic[bmark][key]
  #  #del perf_dic[bmark]['seq']

  mean = { 'geomean': {}}
  for key in perf_dic['atax'].keys():
    geo = 1
    for bmark in bmark_list:
      geo = geo*pow(perf_dic[bmark][key], 1/len(bmark_list))
      mean['geomean'][key] = geo

  perf_dic.update(mean)
  bmark_list.append('geomean')

  return perf_dic, bmark_list

def Plot(perf_dic, bmark_list):
  barWidth = 0.15
  fig, ax = plt.subplots()
  plt.figure(figsize=(16,4))
  plt.rc('axes', axisbelow=True)

  reduced_clang_list = []
  reduced_gcc_list = []
  tulip_clang_list = []
  tulip_gcc_list = []
  for bmark in bmark_list:
    tulip_clang_list.append(perf_dic[bmark]['tulip.clang'])
    tulip_gcc_list.append(perf_dic[bmark]['tulip.gcc'])
    reduced_clang_list.append(perf_dic[bmark]['tulip.reduced.clang'])
    reduced_gcc_list.append(perf_dic[bmark]['tulip.reduced.gcc'])

  clang_pos = np.arange(len(bmark_list))
  gcc_pos = [x + 1*barWidth for x in clang_pos]
  r_clang_pos = [x + 1*barWidth for x in gcc_pos]
  r_gcc_pos = [x + 1*barWidth for x in r_clang_pos]

  color_dic = { 'tulip' : '#C1E1C1', 'tulip+noelle' : '#AEC6CF' }
  style_dic = { 'clang' : '*', 'gcc' : '//' }

  plt.bar(clang_pos, tulip_clang_list, color=color_dic['tulip'], edgecolor='white', hatch=style_dic['clang'], width=barWidth)#, label='Tulip-Clang')
  plt.bar(gcc_pos, tulip_gcc_list, color=color_dic['tulip'], edgecolor='white', hatch=style_dic['gcc'], width=barWidth)#, label='Tulip-GCC')
  plt.bar(r_clang_pos, reduced_clang_list, color=color_dic['tulip+noelle'], edgecolor='white', hatch=style_dic['clang'], width=barWidth)#, label='Tulip-Clang')
  plt.bar(r_gcc_pos, reduced_gcc_list, color=color_dic['tulip+noelle'], edgecolor='white', hatch=style_dic['gcc'], width=barWidth)#, label='Tulip-GCC')

  # Dummy plots for legend
  plt.bar([0], [0], color=color_dic['tulip'], label='Tulip')
  plt.bar([0], [0], color=color_dic['tulip+noelle'], label='Tulip+NOELLE')
  plt.bar([0], [0], hatch=style_dic['clang'], label='clang')
  plt.bar([0], [0], hatch=style_dic['gcc'], label='gcc')

  #plt.yscale('log')
  #plt.ylim(0.5,40)
  plt.grid(axis='y', linestyle='-', linewidth=1)
  yticks = np.linspace(0, 50, 10, dtype=int)
  plt.yticks(yticks, yticks, fontsize=14)
  plt.axhline(0, color='black')
  plt.xlim(min(clang_pos)-1.5*barWidth, max(clang_pos)+barWidth*4.5)
  #plt.tick_params(axis='y', directions='out', left=True, length=5, width=2)
  plt.tick_params(axis='y', which='minor', left=False)
  #plt.tick_params(axis='x', direction='out', right=True, length=5, width=2)
  plt.ylabel('Speedup (x)', fontsize = 18)
  plt.xticks([r + barWidth*3/2 for r in range(len(bmark_list))], bmark_list, rotation='-30', fontsize=16, ha="left")
  for pos in ['right', 'top', 'bottom', 'left']: 
    plt.gca().spines[pos].set_visible(False) 
  plt.legend(
      loc='lower left', bbox_to_anchor= (0.17, 1.01), ncol=4, 
      borderaxespad=0, frameon=False, fontsize=18)

  plt.tight_layout()
  plt.savefig('perf_tulip.pdf')

  return True


def set_config():
  parser = argparse.ArgumentParser()

  parser.add_argument("-n", "--core-num", type=int, default=10,
      help="Number of cores")
  parser.add_argument("-r", "--run_num", type=int, default=5,
      help="Number of runs")

  args = parser.parse_args()

  config = {}
  config['root_path'] = os.path.join(os.getcwd(), "../polybench-cuda")

  #bmark_list = ['gemver', 'atax', 'bicg', 'gesummv', 'mvt']
  bmark_list = ['syrk', 'syr2k', 'gemm', '2mm', '3mm', 'doitgen', 'adi', 'fdtd-2d', 'gemver', 'jacobi-1d-imper', 'jacobi-2d-imper', 'mvt', 'atax', 'bicg', 'gesummv', 'symm', 'lu', 'covariance', 'correlation', 'trmm', 'cholesky', 'nussinov', 'seidel-2d', 'heat-3d']
  #bmark_list = ['syrk', '2mm']

  config['core_num'] = args.core_num
  config['bmark_list'] = bmark_list
  config['run_num'] = args.run_num

  config['result_path'] = os.path.join(config['root_path'], "../", "tulip-results")

  return config

if __name__ == "__main__":
  #tests = ["tulip", "seq"]
  #results = ['seq', 'tulip.clang', 'tulip.gcc', 'tulip.clang.noelle', 'tulip.gcc.noelle']
  tests = ['icx']
  results = ['tulip.icx', 'tulip.icx.noelle']
  #tests = ['nvhpc']
  #results = ['nvhpc.cpu', 'nvhpc.cpu.noelle']

  config = set_config()
  if not config:
    print("Bad configuration, please start over.")
    sys.exit(1)

  print("\n\n### Experiment Start ####")

  if not os.path.exists(config['result_path']):
    os.makedirs(config['result_path'])

  os.chdir(config['result_path'])
  log_path = os.path.join(config['result_path'], "results.log")

  clean_all_bmarks(config['root_path'], config['bmark_list'], config['result_path'])

  perf_list = []
  perf_dic_acc = {}
  for j in range(config['run_num']):
    perf_dic = {}
    for bmark in config['bmark_list']:
      run_all(config['root_path'], bmark, tests)
      perf_list.append(get_time(config['root_path'], bmark, results))
    for i, bmark in enumerate(config['bmark_list']):
      perf_dic.update(perf_list[i])
    perf_dic_acc[j] = perf_dic

  perf_dic = {}
  for bmark in config['bmark_list']:
    perf_dic[bmark] = {}
    for result in results:
      perf_dic[bmark][result] = 0
  temp_bmark_list = config['bmark_list']
  perf_dic, config['bmark_list'] = Postprocess(perf_dic_acc, perf_dic, config['bmark_list'], config['run_num'])

  print(perf_dic)

  os.chdir(config['result_path'])
  #Plot(perf_dic, config['bmark_list'])
        #for i, bmark in enumerate(config['bmark_list']):
              #perf_list_polygeist[i][bmark].update
