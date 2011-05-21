#include<stdio.h>

int binary_search(int *array, int start, int end, int value) {
  int mid_point; 

  if (start > end) {
    return 0;
  }
  mid_point = (start + end) / 2;
  if (*(array + mid_point) == value) {
    return 1;
  } else if (*(array + mid_point) > value) {
      return binary_search(array, start, mid_point - 1, value);
  } else {
    return binary_search(array, mid_point + 1, end, value);
  }
  return 1; 
}
