#include <iostream>
#include <vector>

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
// 24ms, 42.57%
// 16.8MB, 77.73%
class Solution {
public:
    vector<TreeNode*> genTree(int from, int to) {
        vector<TreeNode*> res;
        if(from > to) {
            res.push_back(nullptr);
            return res;
        }
        if(from == to) {
            TreeNode* node = new TreeNode(from);
            return vector<TreeNode*>({node});
        }


        for (int i = from; i <= to; i++) {
            vector<TreeNode*> leftTrees = genTree(from, i - 1);
            vector<TreeNode*> rightTrees = genTree(i + 1, to);

            for (int l = 0; l < leftTrees.size(); ++l) {
                for (int r = 0; r < rightTrees.size(); ++r) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTrees[l];
                    root->right = rightTrees[r];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return genTree(1, n);
    }

    void dumpTree(TreeNode* node) {
        if(node == nullptr) return;

        cout << node->val << " ";
        if(node->left) dumpTree(node->left);
        if(node->right) dumpTree(node->right);
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<TreeNode*> v = s.generateTrees(3);
    for (auto& node : v){
        s.dumpTree(node);
    }
    return 0;
}
