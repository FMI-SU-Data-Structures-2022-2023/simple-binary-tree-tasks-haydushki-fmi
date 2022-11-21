#include "solution.h"
#include <algorithm>
#include <vector>

int countElements(Node* tree) {
    if (!tree) {
        return 0;
    }
    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) {
    if (!tree) {
        return 0;
    }
    if (!tree->left && !tree->right) {
        return 1;
    }
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
    if (!tree) {
        return 0;
    }
    return 1 + std::max(height(tree->left), height(tree->right));
}

int sumElements(Node* tree) {
    if (!tree) {
        return 0;
    }
    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if (!tree) {
        return 0;
    }
    if (!level) {
        return tree->key;
    }
    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}

bool symmetricHelper(Node *left, Node *right)
{
    // Nothing more
    if (!left && !right) {
        return true;
    }

    // One is nullptr when the other isn't => not symmetric
    if (!left || !right) {
        return false;
    }

    // Check subtrees if keys are equal
    return left->key == right->key && symmetricHelper(left->left, right->right)
           && symmetricHelper(left->right, right->left);
}

bool isSymmetric(Node* tree) {
    if (!tree) {
        return false;
    }
    return symmetricHelper(tree->left, tree->right);
}

void visitInorder(Node *tree, std::vector<int> &nodes)
{
    if (!tree) {
        return;
    }
    // Left, Root, Right
    visitInorder(tree->left, nodes);
    nodes.push_back(tree->key);
    visitInorder(tree->right, nodes);
}

bool isBST(Node* tree) {
    if (!tree) {
        return false;
    }

    // If it's BST nodes list should be in ascending order
    std::vector<int> nodes;
    visitInorder(tree, nodes);
    for (std::size_t i = 1; i < nodes.size(); ++i) {
        if (nodes[i - 1] >= nodes[i]) {
            return false;
        }
    }

    return true;
}
