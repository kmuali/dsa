#include <iostream>

void radix_sort(int* arr, int n, int k) {
  int dgt, base, i, counters[10], *tmparr = new int[n];
  for (base = 1; k--; base *= 10) {
    std::cout << "radix_sort  base=" << base << "\n";

    for (dgt = 0; dgt <= 9; dgt++) counters[dgt] = 0;

    for (i = 0; i < n; i++) {
      dgt = (arr[i] / base) % 10;
      counters[dgt]++;
    }

    for (dgt = 1; dgt <= 9; dgt++) counters[dgt] += counters[dgt - 1];

    std::cout << "radix_sort  counters[]=";
    for (dgt = 0; dgt <= 9; dgt++) std::cout << counters[dgt] << "  ";
    std::cout << "\n";

    for (i = n - 1; i >= 0; i--) {
      dgt = (arr[i] / base) % 10;
      tmparr[--counters[dgt]] = arr[i];
    }

    std::cout << "radix_sort  arr[]=";
    for (i = 0; i < n; i++) {
      arr[i] = tmparr[i];
      std::cout << arr[i] << "  ";
    }
    std::cout << "\n";
  }
  delete[] tmparr;
}
