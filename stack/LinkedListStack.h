#include <cstddef>

struct StackNode {
  int dd;
  StackNode* prev;
};

class LinkedListStack {
 private:
  StackNode* ntop;
  int counter;

 public:
  LinkedListStack() {
    ntop = NULL;
    counter = 0;
  }
  void push(int dd) {
    StackNode* ntmp = new StackNode{dd, ntop};
    ntop = ntmp;
    counter++;
  }
  int pop() {
    StackNode* ntmp = ntop->prev;
    int dd = ntop->dd;
    delete ntop;
    ntop = ntmp;
    counter--;
    return dd;
  }
  int last() { return ntop->dd; }
  int count() { return counter; }
  bool empty() { return counter == 0; }
  ~LinkedListStack() {
    StackNode* ntmp;
    while (ntop) {
      ntmp = ntop->prev;
      delete ntop;
      ntop = ntmp;
    }
  }
};
