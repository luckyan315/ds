#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// accept
// 4ms, 81.22%
// 11.6MB, 5.36%
class Solution1 {
public:
    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return 0;
        vector<int> v;
        dfs(root, v);
        int res = INT_MAX;
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); ++i){
            res = min(v[i] - v[i - 1], res);
        }
        return res;
    }

    void dfs(TreeNode* node, vector<int>& v) {
        if(node == nullptr) return;
        v.push_back(node->val);
        dfs(node->left, v);
        dfs(node->right, v);
    }

};

// accept
// 8ms, 39.49%
// 11.3MB, 28.27%
class Solution {
public:
    TreeNode* prev = nullptr;
    int mindiff;

    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return 0;
        mindiff = INT_MAX;
        dfs(root);
        return mindiff;
    }

    void dfs(TreeNode* node) {
        if(node == nullptr) return;
        dfs(node->left);
        if(prev != nullptr) {
            mindiff = min(node->val - prev->val, mindiff);
        }
        prev = node;
        dfs(node->right);
    }
};

int main(int argc, char *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(48);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(49);

    Solution s;
    cout << s.minDiffInBST(root) << endl;

    return 0;
}
