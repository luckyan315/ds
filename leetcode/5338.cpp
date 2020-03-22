#include <iostream>
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

class Solution {
public:
    int maxcnt = 0;

    int longestZigZag(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, int>> que;
        traverse(root, que);

        while (!que.empty()) {
            auto& node = que.front();
            que.pop();

            visit(node.first, true, 0);
            visit(node.first, false, 0);
        }
        return maxcnt;
    }

    void visit(TreeNode* node, bool left, int depth) {
        if(node == nullptr) {
            maxcnt = std::max(maxcnt, --depth);
            return;
        }

        if(left) {
            visit(node->left, !left, depth + 1);
        } else {
            visit(node->right, !left, depth + 1);
        }
    }

    void traverse(TreeNode* root, queue<pair<TreeNode*, int>>& que) {
        if(root == nullptr) return;
        que.push({root, 0});

        if(root->left) traverse(root->left, que);
        if(root->right) traverse(root->right, que);
    }
};

int main(int argc, char *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(6);
    root->right->right->left->right = new TreeNode(7);
    root->right->right->left->right->right = new TreeNode(8);
    root->right->right->left->right->right->right = new TreeNode(9);


    Solution s;
    cout << s.longestZigZag(root) << endl;
    return 0;
}
