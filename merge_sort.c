#include<stdio.h>

void merge(int *array, int start1, int end1, int start2, int end2) {
  int temp_array[end2 - start1 + 1];
  int arr_cnt = 0;
  int p1 = start1;
  int p2 = start2;

  while (p1 < start2 && p2 <= end2) {
    if (*(array + p1) > *(array + p2)) {
      temp_array[arr_cnt++] = *(array + p2);
      p2++;
    } else {
      temp_array[arr_cnt++] = *(array + p1);
      p1++;
    }
  }
  if (p1 < start2) {
    while (p1 < start2) {
      temp_array[arr_cnt++] = *(array + p1);
      p1++;
    }
  } else if (p2 <= end2) {
    while (p2 <= end2) {
      temp_array[arr_cnt++] = *(array + p2);
      p2++;
    }
  } else {
  }

  for (p1 = start1, arr_cnt = 0; p1 <= end2; p1++) {
    *(array + p1) = temp_array[arr_cnt++];
  }
}
  
void merge_sort(int *array, int start, int end) {
  int mid_point;

  if (start < end) {
    mid_point = (start + end) / 2;   
    merge_sort(array, start, mid_point);
    merge_sort(array, mid_point + 1, end);
    merge(array, start, mid_point, mid_point + 1, end);
  }
  else {
    return ;
  }
}
 
int main() {
  int i = 0;
  int array[10] = {1, 5, 3, 9, 7, 4, 2, 8, 6, 0};
  for (; i < 10; i++) {
    printf("%d ", array[i]);
  }
  merge_sort(array, 0, 9);
  printf("\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
