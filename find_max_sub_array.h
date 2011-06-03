#include<stdio.h>

/*
 * Header for finding the maximum sub-array for a given array.
 * 
 * Returns a link to an array of three elements:
 *   start, end, value
 */
typedef struct {
  int left;
  int right;
  int value;
} ArrayParams;

ArrayParams find_overlap_array(int *array, int start, int mid, int end) {
  int i = mid + 2;
  int j = mid - 1;
  int left_max_index = mid;
  int left_max_value = *(array + left_max_index);
  int right_max_index = mid + 1;
  int right_max_value = *(array + right_max_index);
  int current_value = left_max_value;
  ArrayParams overlap_params;

  while (j >= start && left_max_value >= current_value) {
    current_value += *(array + j); 
    if (current_value > left_max_value) {
      left_max_value += *(array + j);
      left_max_index = j;
    }
    j--;
  }
  current_value = right_max_value; 
  while (i <= end && right_max_value >= current_value) {
    current_value += *(array + i);
    if (current_value > right_max_value) {
      right_max_value += *(array + i);
      right_max_index = i;
    }
    i++;
  }
  overlap_params.left = left_max_index;
  overlap_params.right = right_max_index;
  overlap_params.value = left_max_value + right_max_value;
  return overlap_params;
}

ArrayParams find_max_sub_array(int *array, int start, int end) {
  int mid_point = (start + end) / 2;
  ArrayParams left_array;
  ArrayParams right_array;
  ArrayParams mid_array;
  
  if (start < end) {
    left_array = find_max_sub_array(array, start, mid_point);
    right_array = find_max_sub_array(array, mid_point + 1, end);
    mid_array = find_overlap_array(array, start, mid_point, end);
    if((left_array.value > right_array.value) && (left_array.value > mid_array.value)) {
      return left_array;
    } else if ((right_array.value > left_array.value) && (right_array.value > mid_array.value)) {
      return right_array;
    } else {
      return mid_array;
    }
  } else {
      mid_array.left = start;
      mid_array.right = end;
      mid_array.value = *(array + start);
      return mid_array;
  }
} 
