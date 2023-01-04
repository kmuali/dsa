#include <iostream>

#include "bubble_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "selection_sort.h"

void print(int *arr, int n) {
  std::cout << "{" << arr[0];
  for (int i = 1; i < n; i++) std::cout << ", " << arr[i];
  std::cout << "}\n";
}
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define TEST(msg, func, arr)          \
  std::cout << "\n====" msg "====\n"; \
  print(arr, SIZE(arr));              \
  func;                               \
  print(arr, SIZE(arr));              \
  std::cout << "====" msg "====\n";

int main() {
  int arr1[] = {9, 6, 5, 7, 8};
  TEST("bubble_sort", bubble_sort(arr1, SIZE(arr1)), arr1)

  int arr2[] = {4, 7, 5, 3, 6};
  TEST("selection_sort", selection_sort(arr2, SIZE(arr2)), arr2)

  int arr3[] = {3, 5, 1, 4, 2};
  TEST("insertion_sort", insertion_sort(arr3, SIZE(arr3)), arr3);

  int arr4[] = {5, 7, 2, 9, 4, 3, 1, 6, 8};
  TEST("quick_sort", quick_sort(arr4, 0, SIZE(arr4) - 1), arr4);

  int arr5[] = {2, 7, 8, 5, 3, 6, 9, 1, 4};
  TEST("merge_sort", merge_sort(arr5, 0, SIZE(arr5) - 1), arr5);

  int arr6[] = {129, 342, 12, 43, 6, 457, 992, 333, 678, 999};
  TEST("radix_sort", radix_sort(arr6, SIZE(arr6), 3), arr6);

  int arr7[] = {5, 7, 2, 9, 4, 3, 1, 6, 8};
  TEST("heap_sort", heap_sort(arr7, SIZE(arr7)), arr7);

  return 0;
}
