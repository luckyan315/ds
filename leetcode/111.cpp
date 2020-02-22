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


//参考:
//https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/li-jie-zhe-dao-ti-de-jie-shu-tiao-jian-by-user7208/
// accept
// 12ms, beats 84.69%
// 20MB, beats 7.67%
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return (!root->left || !root->right) ? minDepth(root->left) + minDepth(root->right) + 1 :
            min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// 20ms, 34.98%
// 19.7MB, 51.40%
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            res++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if(node->left == nullptr && node->right == nullptr ) return res;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
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

    Solution s;
    cout << s.minDepth(root) << endl;

    return 0;
}
