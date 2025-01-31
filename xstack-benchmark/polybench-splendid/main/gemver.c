
int main(int argc, char ** argv) {
  uint64_t dump_code = strtol(argv[1], ((uint8_t**)0), 10);
  double* A = malloc(7200000000);
  double* u1 = malloc(240000);
  double* v1 = malloc(240000);
  double* u2 = malloc(240000);
  double* v2 = malloc(240000);
  double* w = malloc(240000);
  uint8_t* x = malloc(240000);
  double* y = malloc(240000);
  double* z = malloc(240000);
  memset(x, 0, 240000);
  memset(w, 0, 240000);
for(uint64_t i = 0; i < 30000;   i = i + 1){
  ((double*)u1)[i] = (double)(i);
  ((double*)u2)[i] = (double)((i + 1) / 30000) * 0.5;
  ((double*)v1)[i] = (double)((i + 1) / 30000) * 0.25;
  ((double*)v2)[i] = (double)((i + 1) / 30000) / 6;
  ((double*)y)[i] = (double)((i + 1) / 30000) * 0.125;
  ((double*)z)[i] = (double)((i + 1) / 30000) / 9;
for(uint64_t j = 0; j < 30000;   j = j + 1){
  (((double*)A)+i * 30000)[j] = (double)(i) * (double)(j) / 3.0E+4;
}
}
  if (dump_code == 1) {
for(uint64_t i = 0; i < 30000;   i = i + 1){
  fprintf(stderr, (_OC_str), ((double*)w)[i]);
  if (i % 20 == 0) {
  fputc(10, stderr);
}

}
}

free(A);
free(u1);
free(v1);
free(u2);
free(v2);
free(w);
free(x);
free(y);
free(z);
  return 0;
}

