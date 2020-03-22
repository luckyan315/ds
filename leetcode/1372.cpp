#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// accept
// 184ms, 87.20%
// 101.7MB, 100.00%
class Solution {
public:
    int maxcnt = 0;
    void dfs(TreeNode* root, bool isLeft, int cnt) {
        maxcnt = max(maxcnt, cnt);
        if(isLeft) {
            // start left
            if(root->left) dfs(root->left, 0, cnt + 1);
            // if no left node, restart from right child
            if(root->right) dfs(root->right, 1, 1);
        } else {
            // start right
            if(root->right) dfs(root->right, 1, cnt + 1);
            // if no right, restart from left child
            if(root->left) dfs(root->left, 0, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root, 0, 0);
        dfs(root, 1, 0);
        return maxcnt;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    // root->left->right = new TreeNode(4);
    // root->left->right->left = new TreeNode(5);
    // root->left->right->right = new TreeNode(6);

    // root->left->right->left->right = new TreeNode(7);

    cout << s.longestZigZag(root) << endl;
    return 0;
}
