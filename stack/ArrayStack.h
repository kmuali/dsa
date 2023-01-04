class ArrayStack {
 private:
  int *arr, top, size;

 public:
  ArrayStack(int maxsize) {
    size = maxsize;
    arr = new int[size];
    top = 0;
  }
  void push(int dd) { arr[top++] = dd; }
  int pop() { return arr[--top]; }
  int last() { return arr[top - 1]; }
  int count() { return top; }
  bool empty() { return !top; }
  bool full() { return top == size; }
  void doublesize() {
    int *tmparr = new int[size * size];
    for (int i = 0; i < top; i++) tmparr[i] = arr[i];
    delete[] arr;
    arr = tmparr;
  }
  ~ArrayStack() { delete[] arr; }
};
