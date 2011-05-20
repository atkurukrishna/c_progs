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

