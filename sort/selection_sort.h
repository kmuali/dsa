#include <iostream>
void selection_sort(int* arr, int n) {
  int tmp, min, i, j;
  for (i = 0; i < n; i++) {
    std::cout << "selection_sort  i=" << i << "\n";
    min = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min]) min = j;
    std::cout << "selection_sort  min=" << min << "\n";
    tmp = arr[min];
    arr[min] = arr[i];
    arr[i] = tmp;
  }
}
