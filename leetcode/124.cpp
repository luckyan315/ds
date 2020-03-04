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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        return root->val + std::max(maxPathSum(root->left), maxPathSum(root->right));
    }
};

int main(int argc, char *argv[])
{
    TreeNode* nodem10 =new TreeNode(-10);
    TreeNode* node9 =new TreeNode(9);
    TreeNode* node20 =new TreeNode(20);
    TreeNode* node15 =new TreeNode(15);
    TreeNode* node7 =new TreeNode(7);

    nodem10->left = node9;
    nodem10->right = node20;
    node20->left = node15;
    node20->right = node7;

    Solution s;
    cout << s.maxPathSum(nodem10) << endl;

    return 0;
}
