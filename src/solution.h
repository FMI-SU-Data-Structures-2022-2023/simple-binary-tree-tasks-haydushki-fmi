#ifndef WEEK6_TREE_H

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
};

int countElements(Node*);
int countLeafs(Node*);
int sumElements(Node*);
int sumElementsAtLevel(Node*, unsigned);
int height(Node*);
bool isBST(Node*);
bool isSymmetric(Node*);

#define WEEK6_TREE_H

#endif //WEEK6_TREE_H
