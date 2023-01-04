class ArrayQueue {
 private:
  int *arr, rear, front, counter, size;

 public:
  ArrayQueue(int maxsize) {
    size = maxsize;
    arr = new int[size];
    front = 0;
    rear = -1;
    counter = 0;
  }
  void enqueue(int dd) {
    rear = (rear + 1) % size;
    arr[rear] = dd;
    counter++;
  }
  int dequeue() {
    int tmp = front;
    front = (front + 1) % size;
    counter--;
    return arr[tmp];
  }
 int getfront() {
    return arr[front];
  }
  int getrear(){
    return arr[rear];
  }
  int count() { return counter; }
  bool empty() { return !counter; }
  bool full() { return counter == size; }
  ~ArrayQueue() { delete[] arr; }
};
