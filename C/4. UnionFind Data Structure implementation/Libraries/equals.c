#include "../Headers/equals.h"

/* Equals function for integers */
int equals_int(void* a, void* b){    
  int* tmp_a = (int*)a;
  int* tmp_b = (int*)b;

  if(*tmp_a == *tmp_b)
      return 1;
    
  return 0;
}

/* Equals function for strings */
int equals_string(void* a, void* b){
  char* tmp_a = (char*)a;
  char* tmp_b = (char*)b;

  if(strcmp(tmp_a, tmp_b) == 0)
    return 1;
  
  return 0;
}

/* Equals function for floating points */
int equals_float(void* a, void* b){
  float* tmp_a = (float*)a;
  float* tmp_b = (float*)b;

  if(*tmp_a == *tmp_b)
    return 1;
  
  return 0;
}
