#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

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
// 4ms, beats 84.79%
// 17MB, beats 5.12%
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, res, path);

        int all = 0;

        for(auto& line : res){
            int sum = 0;
            for(int i = 0; i < line.size(); i++) {
                sum += line[i] * std::pow(10, line.size() - i - 1);
            }
            all += sum;
        }

        return all;
    }

    void dfs(TreeNode* node, vector<vector<int>>& res, vector<int>& path) {
        if(node == nullptr) return;

        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
        }

        dfs(node->left, res, path);
        dfs(node->right, res, path);

        path.pop_back();
    }
};

int main(int argc, char *argv[])
{
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);

    node4->left = node9;
    node4->right = node0;

    node9->left = node5;
    node9->right = node1;

    Solution s;

    cout << s.sumNumbers(node4) << endl;

    return 0;
}
