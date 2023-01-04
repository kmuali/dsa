#include <iostream>

struct Student {
  int id;
  char grade;
};

void count_sort(Student* arr, int n) {
  int counters[6], i;
  Student* tmparr = new Student[n];
  for (i = 0; i < 6; i++) counters[i] = 0;
  for (i = 0; i < n; i++) counters[arr[i].grade - 'A']++;
  std::cout << "count_sort  counters[]=";
  for (i = 0; i < 6; i++) std::cout << counters[i] << "  ";
  std::cout << "\n";
  for (i = 1; i < 6; i++) counters[i] += counters[i - 1];
  std::cout << "count_sort  counters[]=";
  for (i = 0; i < 6; i++) std::cout << counters[i] << "  ";
  std::cout << "\n";
  for (i = n - 1; i >= 0; i--) tmparr[--counters[arr[i].grade - 'A']] = arr[i];
  for (i = 0; i < n; i++) arr[i] = tmparr[i];
  delete[] tmparr;
}

void print(Student* arr, int n) {
  for (int i = 0; i < n; i++)
    std::cout << arr[i].id << ": " << arr[i].grade << "  ";
  std::cout << "\n";
}

int main() {
  Student arr[] = {
      {2001, 'C'}, {2002, 'A'}, {2003, 'C'}, {2004, 'A'},
      {2005, 'C'}, {2006, 'F'}, {2007, 'B'},
  };

  print(arr, 7);
  count_sort(arr, 7);
  print(arr, 7);

  return 0;
}
