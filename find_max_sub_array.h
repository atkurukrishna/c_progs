#include<stdio.h>

/*
 * Header for finding the maximum sub-array for a given array.
 * 
 * Returns a link to an array of three elements:
 *   start, end, value
 */
int *find_overlap_array(int *array, int start, int mid, int end) {
  int i = mid + 2;
  int j = mid - 1;
  int left_max_index = mid;
  int left_max_value = *(array + left_max_index);
  int right_max_index = mid + 1;
  int right_max_value = *(array + right_max_index);
  int current_value = left_max_value;
  int return_array[3];

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
  return_array[0] = left_max_index;
  return_array[1] = right_max_index;
  return_array[2] = left_max_value + right_max_value;
  printf("returning these mid overlap vals %d %d %d\n", return_array[0],
      return_array[1], return_array[2]);
  return return_array;
}

int *find_max_sub_array(int *array, int start, int end) {
  int *left_array;
  int *right_array;
  int *mid_overlap_array;
  int mid_point = (start + end) / 2;
  int *now_array;
  int some_array[3] = {start, end, *(array + start)};
  now_array = some_array;
  
  printf("start and end are %d, %d\n", start, end);
  if (start < end) {
    left_array = find_max_sub_array(array, start, mid_point);
    right_array = find_max_sub_array(array, mid_point + 1, end);
    mid_overlap_array = find_overlap_array(array, start, mid_point, end);
/*
    printf("left values: %d, %d, %d\n", *(left_array), *(left_array + 1), *(left_array + 2));
    printf("right values: %d, %d, %d\n", *(right_array), *(right_array + 1), *(right_array + 2));
    printf("mid overlap values: %d, %d, %d\n", *(mid_overlap_array), *(mid_overlap_array + 1), *(mid_overlap_array + 2));
*/
    if (*(left_array + 2) > *(right_array + 2) && *(left_array + 2) > *(mid_overlap_array + 2)) {
      return left_array;
    } else if (*(right_array + 2) > *(left_array + 2) && *(right_array + 2) > *(mid_overlap_array + 2)) {
      printf("came here in the right return\n");
      return right_array;
    } else {
      printf("came here in the mid return\n");
      printf("%d %d %d\n", *(right_array + 2), *(right_array + 1), *(right_array));
      return mid_overlap_array;
    }
  } else {
    return now_array;
  }
} 
