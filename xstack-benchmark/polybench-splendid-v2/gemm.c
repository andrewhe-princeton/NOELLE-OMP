
int main(int argc, char ** argv) {
  uint32_t _argc = (uint32_t)argc;
  uint8_t** _argv = (uint8_t**)argv;
  uint64_t _call_2e_i = strtol(_argv[1], ((uint8_t**)0), 10);
  uint64_t _call_2e_i70 = strtol(_argv[2], ((uint8_t**)0), 10);
  uint64_t _call_2e_i72 = strtol(_argv[3], ((uint8_t**)0), 10);
  uint64_t _call_2e_i74 = strtol(_argv[4], ((uint8_t**)0), 10);
  uint8_t* _call13 = malloc(_call_2e_i72 * (_call_2e_i70 << 3));
  uint8_t* _call17 = malloc(_call_2e_i74 * (_call_2e_i70 << 3));
  uint8_t* _call21 = malloc((_call_2e_i72 << 3) * _call_2e_i74);
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i70 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i72;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call13+(_call_2e_i72 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = (double)(_polly_2e_indvar) * (double)(_polly_2e_indvar4) / _call_2e_i70;
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i70 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i74;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call17+(_call_2e_i74 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = (double)(_polly_2e_indvar) * (double)(_polly_2e_indvar4) / _call_2e_i70;
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i74 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i72;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call21+(_call_2e_i72 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = (double)(_polly_2e_indvar) * (double)(_polly_2e_indvar4) / _call_2e_i70;
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i70 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i72;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  ((double*)_call13)[(_polly_2e_indvar * _call_2e_i72 + _polly_2e_indvar4)] = *((double*)((_call13+(_call_2e_i72 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) * 2123;
for(uint64_t _polly_2e_indvar14 = 0; _polly_2e_indvar_next15 < _call_2e_i74;  _polly_2e_indvar_next15 = _polly_2e_indvar14 + 1){
  ((double*)_call13)[(_polly_2e_indvar * _call_2e_i72 + _polly_2e_indvar4)] = (((double*)_call13)[(_polly_2e_indvar * _call_2e_i72 + _polly_2e_indvar4)] + *((double*)((_call17+(_call_2e_i74 << 3) * _polly_2e_indvar)+(_polly_2e_indvar14 << 3))) * 32412 * *((double*)((_call21+(_polly_2e_indvar4 << 3))+(_call_2e_i72 << 3) * _polly_2e_indvar14)));
}
}
}
}
  if (_call_2e_i == 1) {
for(uint64_t _indvars_2e_iv31_2e_i = 0; _indvars_2e_iv_2e_next32_2e_i < _call_2e_i70;  _indvars_2e_iv_2e_next32_2e_i = _indvars_2e_iv31_2e_i + 1){
for(uint64_t _indvars_2e_iv_2e_i82 = 0; _indvars_2e_iv_2e_next_2e_i85 < _call_2e_i72;  _indvars_2e_iv_2e_next_2e_i85 = _indvars_2e_iv_2e_i82 + 1){
  fprintf(stderr, (_OC_str), (((double*)_call13)+_indvars_2e_iv31_2e_i * _call_2e_i72)[_indvars_2e_iv_2e_i82]);
  if ((int)(_indvars_2e_iv31_2e_i * _call_2e_i70 + _indvars_2e_iv_2e_i82) % (int)20 == 0) {
  fputc(10, stderr);
}

}
}
  fputc(10, stderr);
}

free(_call13);
free(_call17);
free(_call21);
  return 0;
}
