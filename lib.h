#include<stdio.h>
#include<stdlib.h>

int upper_bound(int value) {
  int i = 10;
  while (value > 10) {
    value = value / 10;
    i *= 10;
  }
  return i;
} 
  
int *generate_random_array_of_size_i(int i) {
  int *array;
  int p = 0;
  int upper_bound_of_i = upper_bound(i);
  array = (int *)malloc(sizeof(int) * i);
  for (; p < i; p++) {
    *(array + p) = rand() % upper_bound_of_i;
  }
  return array;
}

int *copy_arrays(int *array, int i) {
  int p = 0;
  int *array2;
  array2 = (int *)malloc(sizeof(int) * i);
  for (; p < i; p++) {
    *(array2 + p) = *(array + p);
  }
  return array2;
}
