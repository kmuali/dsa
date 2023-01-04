#include <cstddef>
#include <iostream>

struct DoublyNode {
  int dd;
  DoublyNode *prev, *next;
};

class DoublyLinkedList {
 private:
  DoublyNode *first, *last;
  int counter;

 public:
  DoublyLinkedList();
  void insert_first(int dd);
  void insert_last(int dd);
  void insert(int dd, int idx);
  int get_first();
  int get_last();
  int get(int idx);
  void remove_first();
  void remove_last();
  void remove(int idx);
  void remove_all();
  int find(int dd);
  int count();
  bool empty();
  void print_first_to_last();
  void print_last_to_first();
  ~DoublyLinkedList();
};

DoublyLinkedList::DoublyLinkedList() {
  first = NULL;
  last = NULL;
  counter = 0;
}

void DoublyLinkedList::insert_first(int dd) {
  DoublyNode *tmpp = new DoublyNode{dd, NULL, first};
  if (first)
    first->prev = tmpp;
  else
    last = tmpp;
  first = tmpp;
  counter++;
}

void DoublyLinkedList::insert_last(int dd) {
  DoublyNode *tmpp = new DoublyNode{dd, last, NULL};
  if (last)
    last->next = tmpp;
  else
    first = tmpp;
  last = tmpp;
  counter++;
}

void DoublyLinkedList::insert(int dd, int idx) {
  if (idx > 0 && idx < counter) {
    DoublyNode *nextp = first, *tmpp;
    for (int i = 0; i < idx; i++) nextp = nextp->next;
    tmpp = new DoublyNode{dd, nextp->prev, nextp};
    nextp->prev->next = tmpp;
    nextp->prev = tmpp;
    counter++;
  } else if (idx == 0)
    insert_first(dd);
  else
    insert_last(dd);
}

int DoublyLinkedList::get_first() { return first->dd; }

int DoublyLinkedList::get_last() { return last->dd; }

int DoublyLinkedList::get(int idx) {
  DoublyNode *tmpp = first;
  for (int i = 0; i < idx; i++) tmpp = tmpp->next;
  return tmpp->dd;
}

void DoublyLinkedList::remove_first() {
  if (!first) return;
  DoublyNode *tmpp = first->next;
  first->next->prev = NULL;
  delete first;
  first = tmpp;
  counter--;
}

void DoublyLinkedList::remove_last() {
  if (!last) return;
  DoublyNode *tmpp = last->prev;
  last->prev->next = NULL;
  delete last;
  last = tmpp;
  counter--;
}

void DoublyLinkedList::remove(int idx) {
  if (idx > 0 && idx < counter - 1) {
    DoublyNode *tmpp = first;
    for (int i = 0; i < idx; i++) tmpp = tmpp->next;
    tmpp->prev->next = tmpp->next;
    tmpp->next->prev = tmpp->prev;
    delete tmpp;
    counter--;
  } else if (idx == 0)
    remove_first();
  else
    remove_last();
}

void DoublyLinkedList::remove_all() {
  DoublyNode *tmpp;
  while (first) {
    tmpp = first;
    first = first->next;
    delete tmpp;
  }
  last = NULL;
  counter = 0;
}

int DoublyLinkedList::find(int dd) {
  DoublyNode *tmpp = first;
  int idx = 0;
  while (tmpp) {
    if (tmpp->dd == dd) return idx;
    idx++;
    tmpp = tmpp->next;
  }
  return -1;
}

int DoublyLinkedList::count() { return counter; }

bool DoublyLinkedList::empty() { return !counter; }

void DoublyLinkedList::print_first_to_last() {
  DoublyNode *tmpp = first;
  std::cout << "{ ";
  while (tmpp) {
    std::cout << tmpp->dd << " ";
    tmpp = tmpp->next;
  }
  std::cout << "}\n";
}

void DoublyLinkedList::print_last_to_first() {
  DoublyNode *tmpp = last;
  std::cout << "{ ";
  while (tmpp) {
    std::cout << tmpp->dd << " ";
    tmpp = tmpp->prev;
  }
  std::cout << "}\n";
}

DoublyLinkedList::~DoublyLinkedList() { remove_all(); }
