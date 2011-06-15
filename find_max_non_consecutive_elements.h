#include<stdio.h>

/*
 * Found this problem in a scpd class assignment. 
 *
 * Problem statement(slightly modified):
 *  given an array a of length n, for a subset of length i such that:
 *  any two values in the subset cannot be adjacent.
 *
 * Solution:
 *  Recursively find out the value a_i by calculating max of the array with and with
 *  out the current value at i. i.e.
 * for each call, we calculate the max of current n as 
 * max(max(f(n-1,0), f(n-1, 1)), f(n-1, 0) + n)
 *
*/
int recursive_find_max(int *array, int /* length */ n, int /* sign bit */ d) {
  int f__n_1_0, f__n_1_1, f__max_n_1;
  
  if (n == 1) {
    if (d == 0) {
      return 0;
    }
    else {
      return *(array + n - 1);
    }
  } else {
    f__n_1_0 = recursive_find_max(array, n-1, 0);
    f__n_1_1 = recursive_find_max(array, n-1, 1);
    f__max_n_1 = (f__n_1_0 > f__n_1_1 ? f__n_1_0 : f__n_1_1);
    if (d) {
      return (f__n_1_0 + *(array + n - 1));
    }
    else {
      return f__max_n_1;
    }
  }
}
