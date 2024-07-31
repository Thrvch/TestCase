#include "binary_tree.h"
#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

using namespace std;

TEST_GROUP(TreeTest) {
    TreeNode* root;

    void setup() {
        root = nullptr;
    }

    void teardown() {
        freeTree(root);
    }
};

TEST(TreeTest, TestEmptyTree) {
    vector<Path> paths = findDeepestPaths(root);
    CHECK_EQUAL(0, paths.size());
}

TEST(TreeTest, TestSingleNodeTree) {
    root = new TreeNode();
    vector<Path> paths = findDeepestPaths(root);
    CHECK_EQUAL(1, paths.size());
    CHECK_EQUAL(1, paths[0].size());
    CHECK_EQUAL(root, paths[0][0]);
}

TEST(TreeTest, TestTreeWithMultiplePaths) {
    root = new TreeNode();
    root->leftChild = new TreeNode();
    root->rightChild = new TreeNode();
    root->leftChild->leftChild = new TreeNode();
    root->leftChild->rightChild = new TreeNode();

    vector<Path> paths = findDeepestPaths(root);
    CHECK_EQUAL(2, paths.size());
    CHECK_EQUAL(3, paths[0].size());
    CHECK_EQUAL(3, paths[1].size());
}

TEST(TreeTest, TestTreeWithOneDeepestPath) {
    root = new TreeNode();
    root->leftChild = new TreeNode();
    root->rightChild = new TreeNode();
    root->leftChild->leftChild = new TreeNode();

    vector<Path> paths = findDeepestPaths(root);
    CHECK_EQUAL(1, paths.size());
    CHECK_EQUAL(3, paths[0].size());
}

TEST(TreeTest, TestTreeWithLinearLeftBranch) {
    root = new TreeNode();
    root->leftChild = new TreeNode();
    root->leftChild->leftChild = new TreeNode();
    root->leftChild->leftChild->leftChild = new TreeNode();

    vector<Path> paths = findDeepestPaths(root);
    CHECK_EQUAL(1, paths.size());
    CHECK_EQUAL(4, paths[0].size());
}

TEST(TreeTest, TestTreeWithLinearRightBranch) {
    root = new TreeNode();
    root->rightChild = new TreeNode();
    root->rightChild->rightChild = new TreeNode();
    root->rightChild->rightChild->rightChild = new TreeNode();

    vector<Path> paths = findDeepestPaths(root);
    CHECK_EQUAL(1, paths.size());
    CHECK_EQUAL(4, paths[0].size());
}

int main(int argc, char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

