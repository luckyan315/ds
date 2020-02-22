#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// accpets
// 8ms, 42.93%
// 11.4MB, 19.68%
class Solution {
public:
    int dx = 0;
    int dy = 0;
    TreeNode* px = NULL;
    TreeNode* py = NULL;

    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        dfs(root, nullptr, 0, x, dx, &px);
        dfs(root, nullptr, 0, y, dy, &py);
        return px != py && dx == dy;
    }

    void dfs(TreeNode* node, TreeNode* pnode,
             int depth, int dest, int& destDepth, TreeNode** /* out */ destParent) {
        if(node == nullptr) return;
        if (node->val == dest) {
            *destParent = pnode;
            destDepth = depth;
            return;
        }
        dfs(node->left, node, depth + 1, dest, destDepth, destParent);
        dfs(node->right, node, depth + 1, dest, destDepth, destParent);
    }
};

// 8ms, 42.93%
// 15.2MB, 5.16%
class Solution1 {
public:
    unordered_map<int, int> depth;
    unordered_map<int, TreeNode*> parent;

    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        dfs(root, nullptr);
        return parent[x] != parent[y] && depth[x] == depth[y];
    }

    void dfs(TreeNode* node, TreeNode* pnode) {
        if (node != nullptr) {
            depth[node->val] = pnode == nullptr ? 0 : depth[pnode->val] + 1;
            parent[node->val] = pnode;

            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> mock = {1,2,3};
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(6);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution s;
    cout << s.isCousins(root, 4, 5) << endl;

    return 0;
}
