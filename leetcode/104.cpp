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
// 12ms, beats 73.28%
// 21.7MB, beats 100.00%
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 8ms, beats 92.80%
// 19.4MB, beats 29.21%
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        int res = 0;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            res++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
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
    cout << s.maxDepth(root) << endl;

    return 0;
}
