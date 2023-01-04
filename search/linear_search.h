#include <iostream>
int linear_search(int *arr, int n, int trgt) {
  for (int i = 0; i < n; i++) {
    std::cout << "linear_search  i=" << i << "\n";
    if (arr[i] == trgt) return i;
  }
  return -1;
}
