#include<stdio.h>

/*
 * Program to extract inversions for a given array input.
 * The algorithm uses the diver and conquer rule, breaking
 * the array recursively and then, comparing the elements
 * on the way out by sorting the local arrays.
 * The algorithm runs in O(n*lg(n))
 */

int inverses = 0;

void find_inverses(int *array, int start, int mid, int mid_plus_one, int end) {
  int p = start;
  int q = mid_plus_one;
  int temp_array_cnt = 0;
  int temp_array[end - start + 1];

  while (p <= mid && q <= end) {
    if (*(array + p) > *(array + q)) {
      inverses += (mid - p + 1);
      temp_array[temp_array_cnt++] = *(array + q++);
    } else {
      temp_array[temp_array_cnt++] = *(array + p++);
    }
  }

  while (p <= mid) {
    temp_array[temp_array_cnt++] = *(array + p++);
  }
  while (q <= end) {
    temp_array[temp_array_cnt++] = *(array + q++);
  }
  
  for (p = start, temp_array_cnt = 0; p <= end; p++) {
    *(array + p) = temp_array[temp_array_cnt++];
  }
}

void divide_array(int *array, int start, int end) {
  int mid_point = (start + end) / 2;
  if (start >= end) {
    return;
  }
  divide_array(array, start,  mid_point);
  divide_array(array, mid_point + 1, end);
  find_inverses(array, start, mid_point, mid_point + 1, end);
}
