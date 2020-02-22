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
// 4ms, beats 94.89%
// 14.2MB, beats 31.34%

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> layer;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                layer.push_back(node->val);
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(layer);
        }

        reverse(res.begin(), res.end());

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
    vector<vector<int>> res = s.levelOrderBottom(root);

    for (int i = 0; i < res.size(); ++i){
        for(auto& e : res[i]){
            cout << e << " ";
        }
        cout << endl;
    }


    return 0;
}
