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

// accept
// 4ms, 72.39%
// 9.6MB, 10.21%
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* node, vector<int>& res){
        if(node == nullptr) return;
        traverse(node->left, res);
        traverse(node->right, res);
        res.push_back(node->val);
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
    vector<int> res = s.postorderTraversal(root);
    for (auto& e : res) {
        cout << e << " ";
    }

    return 0;
}
