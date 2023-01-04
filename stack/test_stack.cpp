#include <iostream>

#include "ArrayStack.h"
#include "LinkedListStack.h"

#define TEST(stackname, num)              \
  while (num) {                           \
    s.push(num % 2);                      \
    num /= 2;                             \
  }                                       \
  while (s.count()) std::cout << s.pop(); \
  std::cout << "\n";

int main() {
  int num1 = 170;
  ArrayStack s(64);
  TEST(s, num1);

  int num2 = 170;
  LinkedListStack t;
  TEST(t, num2);

  return 0;
}
