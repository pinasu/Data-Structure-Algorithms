#include "../Headers/utils.h"

/*
 * Function to swap two element of the given array based on their index.
 */
void swap(void** array, int i, int j){
	void* tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
