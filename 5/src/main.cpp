#include "binary_tree.h"
#include <iostream>

int main() {
    TreeNode* root = new TreeNode();
    root->leftChild = new TreeNode();
    root->rightChild = new TreeNode();
    root->leftChild->leftChild = new TreeNode();
    root->leftChild->rightChild = new TreeNode();
    root->rightChild->leftChild = new TreeNode();

    std::vector<Path> deepestPaths = findDeepestPaths(root);

    std::cout << "Deepest paths:\n";
    for (const auto& path : deepestPaths) {
        std::cout << "Path: ";
        for (TreeNode* node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    freeTree(root);

    return 0;
}
