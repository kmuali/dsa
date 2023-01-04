#include <iostream>
void bubble_sort(int *arr, int n) {
  bool sorted;
  int tmp, i, iend = n;
  do {
    sorted = true;
    std::cout << "bubble_sort  iend=" << iend << "\n";
    for (i = 1; i < iend; i++) {
      std::cout << "bubble_sort  i=" << i << "\n";
      if (arr[i] < arr[i - 1]) {
        tmp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = tmp;
        sorted = false;
        std::cout << "bubble_sort  swap\n";
      }
    }
    iend--;
  } while (!sorted);
}
