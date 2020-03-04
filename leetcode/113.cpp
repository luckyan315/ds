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
// 16ms, beats 70.53%
// 23.2MB, beats 36.12%
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, res, path, sum);
        return res;
    }

    void dfs(TreeNode* node, vector<vector<int>>& res, vector<int>& path, int sum) {
        if(node == nullptr) return;

        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr && sum == node->val) {
            res.push_back(path);
        }

        dfs(node->left, res, path, sum - node->val);
        dfs(node->right, res, path, sum - node->val);

        path.pop_back();
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
    vector<vector<int>> res = s.pathSum(node5, 22);
    for(auto& line : res) {
        for(auto& e : line) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
