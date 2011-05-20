#include<stdio.h>
#include<stdlib.h>

/* Program to sort a list using recursive insertion sort */

void insert(int *array, int elem_pos) {
  int p = elem_pos - 1;
  int temp_value = *(array + elem_pos);
  if (p < 0) {
    exit (1);
  }
  while (p >= 0 && *(array + p) > temp_value) {
      *(array + p + 1) = *(array + p);
      p--;
  }
  *(array + p + 1) = temp_value;
}

void recursive_insertion_sort(int *array, int end) {
  if (end > 0) {
    recursive_insertion_sort(array, end - 1);
  } else {
    return;
  }
  insert(array, end);
}

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

  
    
