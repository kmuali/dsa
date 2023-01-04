#include <cstdlib>

struct QueueNode {
  int dd;
  QueueNode *next;
};

class LinkedListQueue {
 private:
  QueueNode *front, *rear;
  int counter;

 public:
  LinkedListQueue() {
    front = NULL;
    rear = NULL;
    counter = 0;
  }
  void enqueue(int dd) {
    QueueNode *ntmp = new QueueNode{dd, NULL};
    if (rear)
      rear->next = ntmp;
    else
      front = ntmp;
    rear = ntmp;
    counter++;
  }
  int dequeue() {
    QueueNode *ntmp = front->next;
    int dd = front->dd;
    delete front;
    front = ntmp;
    counter--;
    return dd;
  }
  int getfront() { return front->dd; }
  int getrear() { return rear->dd; }
  int count() { return counter; }
  bool empty() { return !counter; }
  ~LinkedListQueue() {
    QueueNode *ntmp;
    while (front) {
      ntmp = front->next;
      delete front;
      front = ntmp;
    }
  }
};
