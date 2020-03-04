#include <iostream>

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
// 16ms, 62.23%
// 23.9MB, 5.12%
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr && root->val == sum) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum  - root->val);
    }
};

int main(int argc, char *argv[])
{
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node11 = new TreeNode(11);
    TreeNode* node13 = new TreeNode(13);
    TreeNode* node44 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node55 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);

    node5->left = node4;
    node5->right = node8;
    node4->left = node11;
    node11->left = node7;
    node11->right = node2;

    node8->left = node13;
    node8->right = node44;

    node44->left = node55;
    node44->right = node1;

    Solution s;
    cout << s.hasPathSum(node5, 22);
    return 0;
}
