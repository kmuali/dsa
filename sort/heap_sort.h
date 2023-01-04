#include <iostream>

void heapify_node(int *arr, int n, int i) {
  std::cout << "heapify_node  n=" << n << "  i=" << i << "\n";
  int left = i * 2 + 1, right = i * 2 + 2, max = i, tmp;
  if (left < n && arr[left] > arr[max]) max = left;
  if (right < n && arr[right] > arr[max]) max = right;
  if (max != i) {
    std::cout << "heapify_node  swap  max=" << max << "\n";
    tmp = arr[max];
    arr[max] = arr[i];
    arr[i] = tmp;
    heapify_node(arr, n, max);
  }
}

void build_heap_tree(int *arr, int n) {
  std::cout << "build_heap_tree  started\n";
  for (int i = n / 2 - 1; i >= 0; i--) heapify_node(arr, n, i);
  std::cout << "build_heap_tree  end\n";
}

void heap_sort(int *arr, int n) {
  build_heap_tree(arr, n);
  int tmp, m = n;
  while (--m) {
    tmp = arr[0];
    arr[0] = arr[m];
    arr[m] = tmp;
    heapify_node(arr, m, 0);
  }
}
