#include <cstddef>
#include <iostream>

struct BinaryNode {
  int dd;
  BinaryNode *left, *right;
};

class BinarySearchTree {
 private:
  BinaryNode *root;
  BinaryNode *makenode(int dd);
  void insert(BinaryNode *np, int dd);
  bool search(BinaryNode *np, int dd);
  bool remove(BinaryNode **npp, int dd);
  void print_pre_order(BinaryNode *np);
  void print_in_order(BinaryNode *np);
  void print_post_order(BinaryNode *np);
  void remove(BinaryNode *np);

 public:
  BinarySearchTree();
  void insert(int dd);
  bool search(int dd);
  bool remove(int dd);
  void print_pre_order();
  void print_in_order();
  void print_post_order();
  ~BinarySearchTree();
};

BinarySearchTree::BinarySearchTree() { root = NULL; }

BinaryNode *BinarySearchTree::makenode(int dd) {
  return new BinaryNode{dd, NULL, NULL};
}

void BinarySearchTree::insert(int dd) {
  if (root)
    insert(root, dd);
  else
    root = makenode(dd);
}

void BinarySearchTree::insert(BinaryNode *np, int dd) {
  if (dd == np->dd) return;
  if (dd < np->dd) {
    if (np->left)
      insert(np->left, dd);
    else
      np->left = makenode(dd);
  } else {
    if (np->right)
      insert(np->right, dd);
    else
      np->right = makenode(dd);
  }
}

bool BinarySearchTree::search(int dd) { return search(root, dd); }

bool BinarySearchTree::search(BinaryNode *np, int dd) {
  if (!np) return false;
  if (dd == np->dd) return true;
  if (dd < np->dd) return search(np->left, dd);
  return search(np->right, dd);
}

bool BinarySearchTree::remove(int dd) { return remove(&root, dd); }

bool BinarySearchTree::remove(BinaryNode **npp, int dd) {
  BinaryNode *np = *npp;
  if (!np) return false;
  if (dd < np->dd) return remove(&np->left, dd);
  if (dd > np->dd) return remove(&np->right, dd);

  std::cout << "BinarySearchTree::remove(" << dd << ")  ";
  if (!np->left && !np->right) {
    std::cout << "No left nor right => target replaced with NULL\n";
    *npp = NULL;

  } else if (!np->left) {
    std::cout << "No left => target replaced with its right\n";
    *npp = np->right;

  } else if (!np->right) {
    std::cout << "No right => target replaced with its left\n";
    *npp = np->left;

  } else if (!np->left->right) {
    std::cout << "No right of left => right replaces right of left.. then "
                 "target replaced with left\n";
    np->left->right = np->right;
    *npp = np->left;

  } else if (!np->right->left) {
    std::cout << "No left of right => left replaces left of right.. then "
                 "target replaced with right\n";
    np->right->left = np->left;
    *npp = np->right;

  } else {
    std::cout << "Finding rightest of left.. copy its dd to target.. replace "
                 "it with its left\n";
    BinaryNode *tmpp = np->left;
    while (tmpp->right->right) tmpp = tmpp->right;
    np->dd = tmpp->right->dd;
    np = tmpp->right;
    tmpp->right = tmpp->right->left;
  }

  delete np;
  return true;
}

BinarySearchTree::~BinarySearchTree() { remove(root); }

void BinarySearchTree::remove(BinaryNode *np) {
  if (!np) return;
  remove(np->left);
  remove(np->right);
  delete np;
}

void BinarySearchTree::print_pre_order() {
  std::cout << "{ ";
  if (root) {
    print_pre_order(root);
  }
  std::cout << "}\n";
}

void BinarySearchTree::print_pre_order(BinaryNode *np) {
  if (!np) return;
  std::cout << np->dd << " ";
  print_pre_order(np->left);
  print_pre_order(np->right);
}

void BinarySearchTree::print_in_order() {
  std::cout << "{ ";
  if (root) {
    print_in_order(root);
  }
  std::cout << "}\n";
}

void BinarySearchTree::print_in_order(BinaryNode *np) {
  if (!np) return;
  print_in_order(np->left);
  std::cout << np->dd << " ";
  print_in_order(np->right);
}

void BinarySearchTree::print_post_order() {
  std::cout << "{ ";
  if (root) {
    print_post_order(root);
  }
  std::cout << "}\n";
}

void BinarySearchTree::print_post_order(BinaryNode *np) {
  if (!np) return;
  print_post_order(np->left);
  print_post_order(np->right);
  std::cout << np->dd << " ";
}
