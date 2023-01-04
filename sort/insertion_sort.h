#include <iostream>

void insertion_sort(int *arr, int n) {
  int tmp, i, j;
  for (i = 1; i < n; i++) {
    std::cout << "insertion_sort  i=" << i << "\n";
    if (arr[i] < arr[i - 1]) {
      std::cout << "insertion_sort  insert\n";
      tmp = arr[i];
      for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
        std::cout << "insertion_sort  j=" << j << "\n";
        arr[j] = arr[j - 1];
      };
      arr[j] = tmp;
    }
  }
}
