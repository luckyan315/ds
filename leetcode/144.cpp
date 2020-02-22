#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

// 4ms, 71.79%
// 9.6MB, 11.57%
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return vector<int>();
        vector<int> res;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            res.push_back(node->val);
            if(node->right) stack.push(node->right);
            if(node->left) stack.push(node->left);

        }
        return res;
    }
};


// accept
// 4ms, beats 71.79%
// 9.8MB, beats 11.46%
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return vector<int>();
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* node, vector<int>& res) {
        if(node == nullptr) return;
        res.push_back(node->val);
        traverse(node->left, res);
        traverse(node->right, res);
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
    vector<int> res = s.preorderTraversal(root);
    for (auto& e : res) {
        cout << e << " ";
    }

    return 0;
}
