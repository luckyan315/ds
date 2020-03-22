#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// accept
// 4ms, 99.48%
// 22.4MB, 15.80%
class Solution {
public:
    int maxHeight = 0;
    int height(TreeNode* node) {
        if(node == nullptr) return 0;
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        maxHeight = std::max(maxHeight, lHeight + rHeight);
        return 1 + std::max(lHeight, rHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        height(root);
        return maxHeight;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << s.diameterOfBinaryTree(root) << endl;
    return 0;
}
