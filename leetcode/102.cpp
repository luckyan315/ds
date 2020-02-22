#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
// 0ms, beats 100.00%
// 14.2MB, beats 24.42%

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        queue<TreeNode*> que;
        vector<vector<int>> res;
        que.push(root);

        while (!que.empty()) {
            vector<int> layer;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                layer.push_back(node->val);
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(layer);
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> mock = {1,2,3};
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution s;
    vector<vector<int>> res = s.levelOrder(root);
    for (int i = 0; i < res.size(); ++i){
        for(auto& e : res[i]){
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
