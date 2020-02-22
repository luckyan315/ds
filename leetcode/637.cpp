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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// accept
// 20ms, beats 80.69%
// 21.9MB, beats 22.24%
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return vector<double>();
        vector<double> res;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            double avgLayer = 0;
            int len = que.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* node = que.front();
                avgLayer += (double) node->val;
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(avgLayer/len);
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
    vector<double> res = s.averageOfLevels(root);

    for(auto& e : res){
        cout << e << " ";
    }
    cout << endl;



    return 0;
}
