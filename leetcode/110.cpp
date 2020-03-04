#include <iostream>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// accepts
// 12ms, 91.46%
// 43.9MB, 5.01%
class Solution {
public:
    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + std::max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;


        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;

        return abs(height(root->left) - height(root->right)) < 2;
    }
};

int main(int argc, char *argv[])
{
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);

    node3->left = node9;
    node3->right = node20;
    node20->left = node15;
    node20->right = node7;

    node7->left = node4;
    node7->right = node5;

    // node9->left = node1;
    // node9->right = node2;

    // node7->left = node4;
    // node7->right = node5;

    Solution s;
    cout << s.isBalanced(node3) << endl;

    return 0;
}
