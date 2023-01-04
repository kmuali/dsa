#include <iostream>

#include "DoublyLinkedList.h"

#define SIZE(arr) sizeof(arr) / sizeof(arr[0])
#define PRINT                                       \
  std::cout << "ls.count()=" << ls.count() << "\n"; \
  std::cout << "ls.print_first_to_last()  ";        \
  ls.print_first_to_last();                         \
  std::cout << "ls.print_last_to_first()  ";        \
  ls.print_last_to_first();                         \
  std::cout << "\n";

int main() {
  DoublyLinkedList ls;

  PRINT

  int seq[] = {100, 3, 83, 14, 66};
  for (int i = 0; i < SIZE(seq); i++) {
    std::cout << "ls.insert_first(" << seq[i] << ")\n";
    ls.insert_first(seq[i]);
    PRINT
  }

  std::cout << "ls.remove_first()\n";
  ls.remove_first();
  PRINT

  std::cout << "ls.remove_last()\n";
  ls.remove_last();
  PRINT

  for (int i = 0; i < SIZE(seq); i++) {
    std::cout << "ls.insert(" << seq[i] << ", 2)\n";
    ls.insert(seq[i], 2);
    PRINT
  }

  std::cout << "ls.get_first()  ls.get_first()  ls.get(2)\n";
  std::cout << ls.get_first() << "  " << ls.get_last() << "  " << ls.get(2)
            << "\n\n";

  std::cout << "ls.remove(2)\n";
  ls.remove(2);
  PRINT

  std::cout << "ls.remove_all()\n";
  ls.remove_all();
  PRINT

  return 0;
}
