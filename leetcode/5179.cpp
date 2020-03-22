#include <iostream>
#include <vector>
#include <algorithm>

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
// 116ms, 23,4MB
class Solution {
public:
    void traverse(TreeNode* root, vector<TreeNode*>& v){
        if(root == nullptr) return;
        v.push_back(root);
        if(root->left) traverse(root->left, v);
        if(root->right) traverse(root->right, v);
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        vector<TreeNode*> v;

        traverse(root, v);

        sort(v.begin(), v.end(), [&](TreeNode* a, TreeNode* b) -> bool {
                if(a->val < b->val) return true;
                return false;
            });

        vector<int> vis(v.size(), 0);
        return generateBST(0, v.size() - 1, v, vis);
    }

    TreeNode* generateBST(int start, int end, vector<TreeNode*>& v, vector<int>& vis) {
        if(start > end) return nullptr;

        int mid = (start + end) / 2;
        if(vis[mid] == 1) return nullptr;
        vis[mid] = 1;
        TreeNode* node = v[mid];
        node->left = generateBST(start, mid - 1, v, vis);
        node->right = generateBST(mid + 1, end, v, vis);
        return node;
    }
};

// accept
// 184ms, 46.2MB
class Solution1 {
public:
    void traverse(TreeNode* root, vector<int>& v){
        if(root == nullptr) return;
        v.push_back(root->val);
        if(root->left) traverse(root->left, v);
        if(root->right) traverse(root->right, v);
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        vector<int> v;

        traverse(root, v);

        sort(v.begin(), v.end(), [&](int a, int b) -> bool {
                if(a < b) return true;
                return false;
            });

        return generateBST(0, v.size() -1 , v);
    }

    TreeNode* buildTree(int start,int last, vector<int>& nums)
        {
            int mid = (start + last) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            if(start == last)
            {
                return root;
            }
            if(start <= mid - 1)
            {
                root->left = buildTree(start, mid-1, nums);
            }
            if(mid+1 <=  last)
            {
                root->right = buildTree(mid+1, last, nums);
            }
            return root;
        }
    TreeNode* generateBST(int start, int end, vector<int>& v) {
        int mid = (start + end) / 2;

        TreeNode* node = new TreeNode(v[mid]);
        if(start == end) return node;
        if(start <= mid - 1) node->left = generateBST(start, mid - 1, v);
        if(mid + 1 <= end) node->right = generateBST(mid + 1, end, v);

        return node;
    }
};

void traverseBST(TreeNode* root){
    if(root == nullptr) return;
    if(root->left) traverseBST(root->left);
    cout << root->val << " ";
    if(root->right) traverseBST(root->right);
}

int main(int argc, char *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution s;
    TreeNode* node = s.balanceBST(root);
    traverseBST(node);
    return 0;
}
