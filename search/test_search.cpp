#include <iostream>

#include "binary_search.h"
#include "linear_search.h"

#define N 7

int main() {
  int arr[N] = {2, 4, 8, 16, 32, 64, 1000};

  std::cout << linear_search(arr, N, 1000) << "\n";
  std::cout << binary_search(arr, N, 1000) << "\n";
  std::cout << rec_binary_search(arr, 0, N - 1, 1000) << "\n";

  return 0;
}

