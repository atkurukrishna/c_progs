#include "recursive_insertion_sort.h"

int main() {
  int i = 0;
  int array[10] = {1, 5, 3, 9, 7, 4, 2, 8, 6, 0};
  for (; i < 10; i++) {
    printf("%d ", array[i]);
  }
  recursive_insertion_sort(array, 9);
  printf("\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}

  
    
