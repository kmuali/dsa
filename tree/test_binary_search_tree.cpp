#include <iostream>

#include "BinarySearchTree.h"

#define PRINT                               \
  std::cout << "tree.print_pre_order()  ";  \
  tree.print_pre_order();                   \
  std::cout << "tree.print_in_order()  ";   \
  tree.print_in_order();                    \
  std::cout << "tree.print_post_order()  "; \
  tree.print_post_order();

#define SIZE(arr) sizeof(arr) / sizeof(arr[0])

int main() {
  BinarySearchTree tree;

  int seq[] = {25, 20, 36, 10, 22, 30, 40, 5, 12, 28, 38, 48};

  for (int i = 0; i < SIZE(seq); i++) {
    std::cout << "\ntree.insert(" << seq[i] << ")\n";
    tree.insert(seq[i]);
    PRINT
  }

  int seq2[] = {36, 22, 20, 90};

  for (int i = 0; i < SIZE(seq2); i++) {
    std::cout << "\ntree.search(" << seq2[i] << ") => " << tree.search(seq2[i])
              << "\n";
    std::cout << "tree.remove(" << seq2[i] << ")\n";
    tree.remove(seq2[i]);
    PRINT
  }

  return 0;
}
