#ifndef SRC_BINARY_TREE_H_
#define SRC_BINARY_TREE_H_

#include <vector>

struct TreeNode {
	TreeNode* leftChild;
    TreeNode* rightChild;
};

using Path = std::vector<TreeNode*>;

void findDeepestPathsRecursive(TreeNode* root, int currentDepth, int& maxDepth, Path& currentPath, std::vector<Path>& deepestPaths);

std::vector<Path> findDeepestPaths(TreeNode* root);

void freeTree(TreeNode* root);

#endif /* SRC_BINARY_TREE_H_ */
