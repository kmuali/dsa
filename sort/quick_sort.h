#include <iostream>

void quick_sort(int *arr, int s, int e) {
  if (s >= e) return;
  int pivot = arr[s], i = s + 1, j = e, tmp;
  while (1) {
    while (i < e && arr[i] < pivot) {
      i++;
    }
    while (j > s && arr[j] >= pivot) {
      j--;
    }
    std::cout << "quick_sort  pivot=" << pivot << "  i=" << i << "  j=" << j
              << "\n";
    if (i >= j) break;
    std::cout << "quick_sort  swap\n";
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
  arr[s] = arr[j];
  arr[j] = pivot;
  quick_sort(arr, s, j - 1);
  quick_sort(arr, j + 1, e);
}
