#include <cstddef>
#include <iostream>

int main() {
  int arr[3][5][10][20];

  int *target = &arr[2][3][6][7];

  std::cout << "Real: " << 2001 + (size_t)target - (size_t)&arr << "\n";
  std::cout << "Calculated: "
            << 2001 + (((2 * 5 + 3) * 10 + 6) * 20 + 7) * sizeof(int) << "\n";

  return 0;
}
