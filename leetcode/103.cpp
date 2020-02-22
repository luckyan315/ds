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

// accept
// 0ms, beats 100.00%
// 13.7MB, beats 15.58%

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        bool right2left = false;
        queue<TreeNode*> que;
        vector<vector<int>> res;
        que.push(root);

        while (!que.empty()) {
            vector<int> layer;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                layer.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            if (right2left) reverse(layer.begin(), layer.end());
            right2left = !right2left;

            res.push_back(layer);
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> mock = {1,2,3};
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution s;
    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for (int i = 0; i < res.size(); ++i){
        for(auto& e : res[i]){
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
