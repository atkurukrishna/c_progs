#include<stdio.h>

/* Recursive way to do merge sort */


void merge(int *array, int start1, int end1, int start2, int end2) {
  int s1 = start1;
  int s2 = start2;
  int e1 = end1;
  int e2 = end2;
  int temp_array[end2 - start1 + 1];
  int arr_cnt = 0;
  int p1 = s1;
  int p2 = s2;

  while (p1 < s2 && p2 <= e2) {
    if (*(array + p1) > *(array + p2)) {
      temp_array[arr_cnt++] = *(array + p2);
      p2++;
    } else {
      temp_array[arr_cnt++] = *(array + p1);
      p1++;
    }
  }
  if (p1 < s2) {
    while (p1 < s2) {
      temp_array[arr_cnt++] = *(array + p1);
      p1++;
    }
  } else if (p2 <= e2) {
    while (p2 <= e2) {
      temp_array[arr_cnt++] = *(array + p2);
      p2++;
    }
  } else {
  / * do nothing */
  }

  for (p1 = start1, arr_cnt = 0; p1 <= end2; p1++) {
    *(array + p1++) = temp_array[arr_cnt++];
  }
}
  
/* function takes the following:
  *array - pointer to the array
  start - begenning of the array
  end - end of the array
*/
void merge_sort(int *array, int start, int end) {
  if (start < end) {
    merge_sort(array, start, (start + end) / 2);
    merge_sort(array, ((start + end) / 2 ) + 1, end);
    merge(array, start, (start + end) / 2, ((start + end) / 2) + 1, end);
  }
  else {
    return ;
  }
}
 


int main() {
  int array[10] = {1, 5, 3, 9, 7, 4, 2, 8, 6, 0};
  merge_sort(array, 0, 9);
  

  /* write merge sort to sort this array */
  
