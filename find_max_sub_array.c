#include "find_max_sub_array.h"

int main() {
  int array[4] = {-3, -4, 2, 5};
  int *array_vals;
  printf("came here 1 \n");
  
  array_vals = find_max_sub_array(array, 0, 3);
  printf("vales are %d %d %d\n", array_vals[0], array_vals[1],
      array_vals[2]);
  return 0;
}
  
