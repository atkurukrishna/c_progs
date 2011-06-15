#include "find_max_non_consecutive_elements.h"

int main() {

int array[6] = {-22, -5, 3, 10, 15, 6};

int with_n = recursive_find_max(array, 6, 1);
int with_out_n = recursive_find_max(array, 6, 0);
printf("The max non_consecutive elements sum is %d\n", (with_n > with_out_n ? with_n : with_out_n));

return 1;
}
