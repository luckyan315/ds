#include <iostream>
#include <queue>
#include <algorithm>

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
// 24ms, beats 26.90%
// 24MB, beats 5.13%
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(root->left == nullptr &&
            root->right == nullptr) return true;
        long prev = LONG_MIN;
        return traverse(root, prev);
    }

    bool traverse(TreeNode* root, long& prev) {
        if(root == nullptr) return true;

        if(root->left) if(!traverse(root->left, prev)) return false;

        // cout << root->val << " ";
        if(prev >= root->val) return false;
        prev = root->val;

        if(root->right) if(!traverse(root->right, prev)) return false;

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // TreeNode* root = new TreeNode(5);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(4);
    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(6);

    TreeNode* root = new TreeNode(-2147483648);
    root->right = new TreeNode(2147483647);

    cout << s.isValidBST(root) << endl;
    return 0;
}
