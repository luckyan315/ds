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
    vector<vector<int>> res;

    int pathSum(TreeNode* root, int sum) {
        vector<int> path;
        traverse(root, path, sum);

        return res.size();
    }

    int traverse(TreeNode* root, vector<int>& path, int sum) {
        if(root == nullptr) return sum;


    }
};
