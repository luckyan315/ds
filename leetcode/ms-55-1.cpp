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
// 12ms, beats 73.28%
// 21.7MB, beats 100.00%
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    node3->left = node9;
    node3->right = node20;
    node20->left = node15;
    node20->right = node7;

    cout << s.maxDepth(node3) << endl;
    return 0;
}
