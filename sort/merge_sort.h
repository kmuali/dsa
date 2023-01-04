#include <iostream>

void merge(int *arr, int s1, int e1, int s2, int e2) {
  int *tmparr = new int[e2 - s1 + 1], k1 = s1, k2 = s2, k3 = 0;
  while (k1 <= e1 && k2 <= e2) {
    if (arr[k1] <= arr[k2])
      tmparr[k3++] = arr[k1++];
    else
      tmparr[k3++] = arr[k2++];
  }
  while (k1 <= e1) tmparr[k3++] = arr[k1++];
  while (k2 <= e2) tmparr[k3++] = arr[k2++];
  while (k3--) arr[s1 + k3] = tmparr[k3];
  delete[] tmparr;
}

void merge_sort(int *arr, int s, int e) {
  if (s >= e) return;
  int m = (s + e) / 2;
  std::cout << "merge_sort  s=" << s << "  e=" << e << "  m=" << m << "\n";
  merge_sort(arr, s, m);
  merge_sort(arr, m + 1, e);
  merge(arr, s, m, m + 1, e);
}
