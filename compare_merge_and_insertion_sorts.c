#include <time.h>
#include "lib.h"
#include "merge_sort.h"
#include "recursive_insertion_sort.h"

int main() {
  int i = 10;
  int *array;
  clock_t start, end;
  int merge_sort_times[990];
  int insertion_sort_times[990];

  for(; i < 1000; i++) {
    array = generate_random_array_of_size_i(i);
    start = clock();
    merge_sort(array, 0, i-1);
    end = clock();
    merge_sort_times[i - 10] = (end - start);
 
    array = generate_random_array_of_size_i(i);
    start = clock();
    recursive_insertion_sort(array, i - 1);
    end = clock();
    insertion_sort_times[i - 10] = (end - start);
  }
  for (i = 0; i < 990; i++) {
    printf("%d ", merge_sort_times[i]);
    printf("%d \n", insertion_sort_times[i]);
  }
  return 0;
}
