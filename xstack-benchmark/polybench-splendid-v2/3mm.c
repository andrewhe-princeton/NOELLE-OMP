
int main(int argc, char ** argv) {
  uint32_t _argc = (uint32_t)argc;
  uint8_t** _argv = (uint8_t**)argv;
  uint64_t _call_2e_i = strtol(_argv[1], ((uint8_t**)0), 10);
  uint64_t _call_2e_i137 = strtol(_argv[2], ((uint8_t**)0), 10);
  uint64_t _call_2e_i139 = strtol(_argv[3], ((uint8_t**)0), 10);
  uint64_t _call_2e_i141 = strtol(_argv[4], ((uint8_t**)0), 10);
  uint64_t _call_2e_i143 = strtol(_argv[5], ((uint8_t**)0), 10);
  uint64_t _call_2e_i145 = strtol(_argv[6], ((uint8_t**)0), 10);
  uint8_t* _call21 = malloc(_call_2e_i139 * (_call_2e_i137 << 3));
  uint8_t* _call25 = malloc(_call_2e_i141 * (_call_2e_i137 << 3));
  uint8_t* _call29 = malloc(_call_2e_i141 * (_call_2e_i139 << 3));
  uint8_t* _call33 = malloc(_call_2e_i143 * (_call_2e_i139 << 3));
  uint8_t* _call37 = malloc(_call_2e_i145 * (_call_2e_i139 << 3));
  uint8_t* _call41 = malloc((_call_2e_i143 << 3) * _call_2e_i145);
  uint8_t* _call45 = malloc(_call_2e_i143 * (_call_2e_i137 << 3));
for(uint64_t _indvars_2e_iv171_2e_i = 0; _indvars_2e_iv_2e_next172_2e_i < _call_2e_i137;  _indvars_2e_iv_2e_next172_2e_i = _indvars_2e_iv171_2e_i + 1){
for(uint64_t _indvars_2e_iv167_2e_i = 0; _indvars_2e_iv_2e_next168_2e_i < _call_2e_i141;  _indvars_2e_iv_2e_next168_2e_i = _indvars_2e_iv167_2e_i + 1){
  (((double*)_call25)+_indvars_2e_iv171_2e_i * _call_2e_i141)[_indvars_2e_iv167_2e_i] = (double)(_indvars_2e_iv171_2e_i) * (double)(_indvars_2e_iv167_2e_i) / (double)(_call_2e_i137);
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i141 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i139;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call29+(_call_2e_i139 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = (double)(_polly_2e_indvar) * (double)((_polly_2e_indvar4 + 1)) / _call_2e_i139;
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i139 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i145;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call37+(_call_2e_i145 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = (double)(_polly_2e_indvar) * (double)((_polly_2e_indvar4 + 3)) / (double)(_call_2e_i143);
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i145 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i143;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call41+(_call_2e_i143 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = (double)(_polly_2e_indvar) * (double)((_polly_2e_indvar4 + 2)) / (double)(_call_2e_i141);
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i137 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i139;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call21+(_call_2e_i139 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = 0;
  ((double*)_call21)[(_polly_2e_indvar * _call_2e_i139 + _polly_2e_indvar4)] = 0;
for(uint64_t _polly_2e_indvar15 = 0; _polly_2e_indvar_next16 < _call_2e_i141;  _polly_2e_indvar_next16 = _polly_2e_indvar15 + 1){
  ((double*)_call21)[(_polly_2e_indvar * _call_2e_i139 + _polly_2e_indvar4)] = (((double*)_call21)[(_polly_2e_indvar * _call_2e_i139 + _polly_2e_indvar4)] + *((double*)((_call25+(_call_2e_i141 << 3) * _polly_2e_indvar)+(_polly_2e_indvar15 << 3))) * *((double*)((_call29+(_polly_2e_indvar4 << 3))+(_call_2e_i139 << 3) * _polly_2e_indvar15)));
}
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i139 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i143;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call33+(_call_2e_i143 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = 0;
  ((double*)_call33)[(_polly_2e_indvar * _call_2e_i143 + _polly_2e_indvar4)] = 0;
for(uint64_t _polly_2e_indvar15 = 0; _polly_2e_indvar_next16 < _call_2e_i145;  _polly_2e_indvar_next16 = _polly_2e_indvar15 + 1){
  ((double*)_call33)[(_polly_2e_indvar * _call_2e_i143 + _polly_2e_indvar4)] = (((double*)_call33)[(_polly_2e_indvar * _call_2e_i143 + _polly_2e_indvar4)] + *((double*)((_call37+(_call_2e_i145 << 3) * _polly_2e_indvar)+(_polly_2e_indvar15 << 3))) * *((double*)((_call41+(_polly_2e_indvar4 << 3))+(_call_2e_i143 << 3) * _polly_2e_indvar15)));
}
}
}
}
  #pragma omp parallel 
{

#pragma omp for schedule(static)
for(uint64_t _polly_2e_indvar = 0; _polly_2e_indvar<=(_call_2e_i137 - 1);_polly_2e_indvar+=1){
for(uint64_t _polly_2e_indvar4 = 0; _polly_2e_indvar_next5 < _call_2e_i143;  _polly_2e_indvar_next5 = _polly_2e_indvar4 + 1){
  *((double*)((_call45+(_call_2e_i143 << 3) * _polly_2e_indvar)+(_polly_2e_indvar4 << 3))) = 0;
  ((double*)_call45)[(_polly_2e_indvar * _call_2e_i143 + _polly_2e_indvar4)] = 0;
for(uint64_t _polly_2e_indvar14 = 0; _polly_2e_indvar_next15 < _call_2e_i139;  _polly_2e_indvar_next15 = _polly_2e_indvar14 + 1){
  ((double*)_call45)[(_polly_2e_indvar * _call_2e_i143 + _polly_2e_indvar4)] = (((double*)_call45)[(_polly_2e_indvar * _call_2e_i143 + _polly_2e_indvar4)] + *((double*)((_call21+(_call_2e_i139 << 3) * _polly_2e_indvar)+(_polly_2e_indvar14 << 3))) * *((double*)((_call33+(_polly_2e_indvar4 << 3))+(_call_2e_i143 << 3) * _polly_2e_indvar14)));
}
}
}
}
  if (_call_2e_i == 1) {
for(uint64_t _indvars_2e_iv31_2e_i = 0; _indvars_2e_iv_2e_next32_2e_i < _call_2e_i137;  _indvars_2e_iv_2e_next32_2e_i = _indvars_2e_iv31_2e_i + 1){
for(uint64_t _indvars_2e_iv_2e_i153 = 0; _indvars_2e_iv_2e_next_2e_i156 < _call_2e_i143;  _indvars_2e_iv_2e_next_2e_i156 = _indvars_2e_iv_2e_i153 + 1){
  fprintf(stderr, (_OC_str), (((double*)_call45)+_indvars_2e_iv31_2e_i * _call_2e_i143)[_indvars_2e_iv_2e_i153]);
  if ((int)(_indvars_2e_iv31_2e_i * _call_2e_i137 + _indvars_2e_iv_2e_i153) % (int)20 == 0) {
  fputc(10, stderr);
}

}
}
  fputc(10, stderr);
}

free(_call21);
free(_call25);
free(_call29);
free(_call33);
free(_call37);
free(_call41);
free(_call45);
  return 0;
}

