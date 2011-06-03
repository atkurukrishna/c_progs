#include "find_max_sub_array.h"

int main() {
  int array[4] = {-3, -4, -2};
  
  ArrayParams array_vals = find_max_sub_array(array, 0, 2);
  printf("vales are %d %d %d\n", array_vals.left, array_vals.right,
      array_vals.value);
  return 0;
}
  
