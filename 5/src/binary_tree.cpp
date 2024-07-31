#include "binary_tree.h"
#include <algorithm>

using namespace std;

void findDeepestPathsRecursive(TreeNode* root, int currentDepth, int& maxDepth, Path& currentPath, vector<Path>& deepestPaths) {
    if (root == nullptr) {
        return;
    }

    currentPath.push_back(root);

    if (currentDepth > maxDepth) {
        maxDepth = currentDepth;
        deepestPaths.clear();
        deepestPaths.push_back(currentPath);
    } else if (currentDepth == maxDepth) {
        deepestPaths.push_back(currentPath);
    }

    findDeepestPathsRecursive(root->leftChild, currentDepth + 1, maxDepth, currentPath, deepestPaths);
    findDeepestPathsRecursive(root->rightChild, currentDepth + 1, maxDepth, currentPath, deepestPaths);

    currentPath.pop_back();
}

std::vector<Path> findDeepestPaths(TreeNode* root) {
    int maxDepth = 0;
    vector<Path> deepestPaths;
    Path currentPath;
    findDeepestPathsRecursive(root, 1, maxDepth, currentPath, deepestPaths);
    return deepestPaths;
}

void freeTree(TreeNode* root) {
    if (root) {
        freeTree(root->leftChild);
        freeTree(root->rightChild);
        delete root;
    }
}
