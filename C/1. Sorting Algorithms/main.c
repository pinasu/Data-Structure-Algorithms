#include "Headers/std.h"
#include "Headers/algorithms.h"

/*
 * Constant for the array initial length
 */
#define ARRAY_LENGTH 10

/*
 * Application main
 */
int main(int argc, char const *argv[]){
  Arraylist alist = (Arraylist)read_file(ARRAY_LENGTH);

  return 0;
}
