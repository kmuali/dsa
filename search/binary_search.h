#include <iostream>
int binary_search(int *arr, int n, int trgt) {
  int i = 0, j = n - 1, m;
  while (i <= j) {
    int m = (i + j) / 2;
    std::cout << "binary_search  i=" << i << "  j=" << j << "  m=" << m << "\n";
    if (trgt == arr[m]) return m;
    if (trgt < arr[m])
      j = m - 1;
    else
      i = m + 1;
  }
  return -1;
}

int rec_binary_search(int *arr, int i, int j, int trgt) {
  if (i > j) return -1;
  int m = (i + j) / 2;
  std::cout << "rec_binary_search  i=" << i << "  j=" << j << "  m=" << m
            << "\n";
  if (trgt == arr[m]) return m;
  if (trgt < arr[m]) return rec_binary_search(arr, i, m - 1, trgt);
  return rec_binary_search(arr, m + 1, j, trgt);
}
