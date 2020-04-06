#include <iostream>
#include <vector>
#include <unordered_map>

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
// 24ms, beats 62.21%
class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return buildTree(postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode*  buildTree(vector<int>& postorder, int postL, int postR, int inL, int inR) {
        if(postL > postR || inL > inR) return nullptr;

        TreeNode* root = new TreeNode(postorder[postR]);
        int m = mp[postorder[postR]];
        root->left = buildTree(postorder, postL, postR - (inR - m) - 1,
                                inL, m - 1);
        root->right = buildTree(postorder, postR - (inR - m), postR - 1,
                               m + 1, inR);

        return root;
    }


};
