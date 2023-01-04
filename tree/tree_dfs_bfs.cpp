#include <iostream>

#include "../queue/ArrayQueue.h"
#include "../stack/ArrayStack.h"

struct TreeNode {
  char name, father;
  int order;
};

void print_dfs(TreeNode *tree, int n) {
  ArrayStack s(n);
  char *sons = new char[n], father;
  int i, sons_count;
  for (i = 0; i < n; i++)
    if (tree[i].father == '0') {
      s.push(tree[i].name);
      break;
    }

  while (s.count()) {
    father = s.pop();
    std::cout << father << " ";
    sons_count = 0;
    for (i = 0; i < n; i++)
      if (tree[i].father == father) {
        sons[tree[i].order] = tree[i].name;
        sons_count++;
      }
    for (i = sons_count; i >= 1; i--) s.push(sons[i]);
  }
  delete[] sons;
}

void print_bfs(TreeNode *tree, int n) {
  ArrayQueue q(n);
  char *sons = new char[n], father;
  int i, sons_count;
  for (i = 0; i < n; i++)
    if (tree[i].father == '0') {
      q.enqueue(tree[i].name);
      break;
    }

  while (q.count()) {
    father = q.dequeue();
    std::cout << father << " ";
    sons_count = 0;
    for (i = 0; i < n; i++)
      if (tree[i].father == father) {
        sons[tree[i].order] = tree[i].name;
        sons_count++;
      }
    for (i = 1; i <= sons_count; i++) q.enqueue(sons[i]);
  }
  delete[] sons;
}

int main() {
  TreeNode tree[] = {{'A', 'M', 2}, {'B', 'M', 1}, {'C', 'A', 1},
                     {'D', 'H', 3}, {'F', 'H', 1}, {'G', 'H', 2},
                     {'H', 'M', 3}, {'K', 'B', 2}, {'M', '0', 0},
                     {'P', 'K', 2}, {'X', 'K', 1}, {'Y', 'B', 1}};

  std::cout << "DFS: ";
  print_dfs(tree, 12);

  std::cout << "\nBFS: ";
  print_bfs(tree, 12);
  std::cout << "\n";

  return 0;
}
