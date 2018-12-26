#include "../Headers/compare.h"

/* Compare function for integers */
int compare_int(void* a, void* b){
    int* tmp_a = (int*)a;
    int* tmp_b = (int*)b;

    if(*tmp_a < *tmp_b)
        return -1;
    else if(*tmp_a == *tmp_b)
        return 0;
    return 1;
}

/* Compare function for strings */
int compare_string(void* a, void* b){
    char* tmp_a = (char*)a;
    char* tmp_b = (char*)b;

	return strcmp(tmp_a, tmp_b);
}

/* Compare function for floating points */
int compare_float(void* a, void* b){
    float* tmp_a = (float*)a;
    float* tmp_b = (float*)b;

    if(*tmp_a < *tmp_b)
        return -1;
    else if(*tmp_a == *tmp_b)
        return 0;
    return 1;
}
