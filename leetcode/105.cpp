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
// 28ms, beats 51.59%
// 14.9MB, 95.22%
class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return buildTree(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode*  buildTree(vector<int>& preorder, int preL, int preR, int inL, int inR) {
        if(preL > preR || inL > inR) return nullptr;

        TreeNode* root = new TreeNode(preorder[preL]);
        int m = mp[preorder[preL]];
        root->left = buildTree(preorder, preL + 1, m - inL + preL,
                               inL, m - 1);
        root->right = buildTree(preorder, m - inL + preL + 1, preR,
                                m+1, inR);
        return root;
    }
};
