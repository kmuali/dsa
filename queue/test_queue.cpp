#include <iostream>

#include "ArrayQueue.h"
#include "LinkedListQueue.h"

int main() {
  ArrayQueue q(26);

  char ch = 'A';
  while (!q.full()) q.enqueue(ch++);
  while (q.count()) std::cout << (char)q.dequeue();
  std::cout << "\n";

  LinkedListQueue t;
  ch = 'a';
  while (t.count() < 26) t.enqueue(ch++);
  while (t.count()) std::cout << (char)t.dequeue();
  std::cout << "\n";

  return 0;
}
