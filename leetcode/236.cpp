#include <iostream>
#include <vector>
#include <set>

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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr) return nullptr;
        vector<int> parent(50000, 0);
        traverse(root, -1, parent, p, q);

        int cur = p->val;
        set<int> vis;

        parent[root->val] = -1;

        while(cur != -1) {
            vis.insert(cur);
            cur = parent[cur];
        }

        cur = q->val;
        int dest = 0;
        while(cur != -1) {
            if(vis.count(cur) > 0) {
                dest = cur;
                break;
            }
            cur = parent[cur];
        }

        return find(root, dest);
    }

    TreeNode* find(TreeNode* root, int dest) {
        if(root == nullptr) return nullptr;

        if(root->val == dest) return root;
        TreeNode* res = nullptr;
        if(root->left) {
            res = find(root->left, dest);
            if(res) return res;
        }

        if(root->right) {
            res = find(root->right, dest);
            if(res) return res;
        }

        return res;
    }

    void traverse(TreeNode* node, int pnode, vector<int>& parent, TreeNode* p, TreeNode* q) {
        if(node == nullptr) return;
        parent[node->val] = pnode;

        if(node->left) traverse(node->left, node->val, parent, p, q);
        if(node->right) traverse(node->right, node->val, parent, p, q);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    cout << s.lowestCommonAncestor(root, root->left, root->right)->val << endl;
    return 0;
}
