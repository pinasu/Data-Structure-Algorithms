#include "../Headers/algorithms.h"

/*
 * Function: selection_sort
 * -------------------------
 * Selection Sort algorithm implementation for generic types.
 *
 */
void selection_sort(void** array, int l, compare c){
	int i = 0;
	int min = 0;
	int j = 0;
	while(i<l){
		min = i;
		j = i+1;
		while(j<l){
			if(c(array[j], array[min]) < 0)
				min = j;
			j++;
		}
		swap(array, i, min);
		i++;
	}
}

/*
 * Function: insertion_sort
 * -------------------------
 * Insertion Sort algorithm implementation for generic types.
 *
 */
 void insertion_sort(void** array, int l, compare c){
	int i = 0;
	while(i<l){
		int j = i;
		while(j>0 && c(array[j], array[j-1]) < 0){
			swap(array, j, j-1);
			j--;
		}
		i++;
	}
}

/*
 * Function: quick_sort_aux
 * -------------------------
 * Quick Sort auxiliar algorithm implementation for generic types.
 * Here's where the actual recursion happens.
 *
 */
 void quick_sort_aux(void** array, int i, int j, compare c){
	int p = i;
	int l = j;

	if(i==j){
		if(c(array[i],array[p])<0)
			swap(array,p,i);
	}
	else{
		i++;
		while(i<j){
			if(c(array[p],array[i])<0){
				if(c(array[j],array[p])<=0){
					swap(array,i,j);
					i++;
				}
				j--;
			}
			else
				i++;
		}

		if(p<i){
			if(c(array[p],array[i])<0)
				i--;
			if(p<i)
				swap(array,p,i);
		}
		if(i==l)
		   quick_sort_aux(array,p,--i,c);
		else{
		 quick_sort_aux(array,p,i,c);
		 quick_sort_aux(array,j,l,c);
		}
	}
}

/*
 * Function: quick_sort_aux
 * -------------------------
 * Quick Sort algorithm implementation for generic types.
 * This methos only calld quick_sort_aux passing the array pointer, the first
 * and last index of arrayand a compae function.
 *
 */
void quick_sort(void** array, int l, compare c){
	quick_sort_aux(array, 0, l-1, c);
}
