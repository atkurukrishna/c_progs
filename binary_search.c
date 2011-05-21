#include "binary_search.h"
#include "lib.h"
#include<time.h>
#include "merge_sort.h"

int main() {

  int found_value = 0;
  int array[10] = {4, 50, 32, 0, 35, 90, 20, 2, 65, 3};
  clock_t start, stop;

  start = clock(); 
  merge_sort(array, 0, 9);
  found_value = binary_search(array, 0, 9, 3);
  stop = clock();
  if (found_value == 1) {
    printf(" Found value\n");
  } else {
    printf("Found no value\n");
  }
  printf("Clocks taken : %d\n", stop - start);
  return 0;
}
