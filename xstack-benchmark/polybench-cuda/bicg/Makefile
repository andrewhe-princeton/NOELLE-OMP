#POLLY=1
BMARK=bicg
TEST_ARGS=1 10000000000000 10000000000000
PERF_ARGS=0 15000 15000

#ADDITIONAL_PASSES=-dce -bdce --globaldce --unreachableblockelim --instcombine
#ADDITIONAL_PASSES=-dce -bdce --globaldce --unreachableblockelim --instcombine -dce
LOC_PASSES=-dce -bdce --globaldce --unreachableblockelim --instcombine -dce
include ../Makefile.generic
