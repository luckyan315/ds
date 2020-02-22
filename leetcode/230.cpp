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

// 28ms, 44.40%
// 22.2MB, 5.05%
class Solution {
public:
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;

        vector<int> v;
        dfs(root, v);
        return v[k-1];
    }

    void dfs(TreeNode* node, vector<int>& v) {
        if(node == nullptr) return;
        dfs(node->left, v);
        v.push_back(node->val);
        dfs(node->right, v);
    }
};

int main(int argc, char *argv[])
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution s;
    cout << s.kthSmallest(root, atoi(argv[1])) << endl;

    return 0;
}
