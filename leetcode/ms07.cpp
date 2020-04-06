#include <iostream>
#include <vector>
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
// 104ms, 12.72%
// 20.6MB, 100.00%
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int preBegin, int preEnd,
                        vector<int>& inorder, int inBegin, int inEnd) {
        if(preBegin > preEnd || inBegin > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preBegin]);
        int pivot = 0;
        for(int i = 0; i < inorder.size(); ++i) {
            if(inorder[i] == preorder[preBegin]) {
                pivot = i;
            }
        }

        root->left = buildTree(preorder, preBegin + 1, pivot - inBegin + preBegin,
                               inorder, inBegin, pivot);
        root->right = buildTree(preorder, pivot - inBegin + preBegin + 1, preEnd,
                                inorder, pivot + 1, inEnd);

        return root;
    }
};

int main(int argc, char *argv[])
{
    // Solution s;
    // vector<int> preorder = {};
    // s.buildTree();
    return 0;
}
