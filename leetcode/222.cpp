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
// 算法参考：
// https://www.jianshu.com/p/48c7a4ca7636
// https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-47/
// 64ms, beats 7.51%
// 28.7MB, beats 28.46%
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int height = depth(root);
        int hRight = depth(root->right);
        if(hRight == height - 1) {
            int cnt = (1 << (height - 1)) + countNodes(root->right);
            // cout << "visit: " << root->val << " height: " << height << " right height: " << hRight << " count: " << cnt << endl;
            return cnt;
        } else {
            int cnt = (1 << (height - 2)) + countNodes(root->left); //height - hRight == 1
            // cout << "visit: " << root->val << " height: " << height << " right height: " << hRight << " count: " << cnt << endl;
            return cnt;
        }

    }

    int depth(TreeNode* node) {
        if(node == nullptr) return 0;
        // cout << "visit node: " << node->val << endl;
        int depth = 0;
        while (node) {
            depth++;
            node = node->left;
        }
        // cout << "depth: " << depth << endl;
        return depth;
    }
};


// accept
// 44ms, 48.14%
// 28.7MB, beats 39.06%
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// accept
// 40ms, beats 68.67%
// 29.4MB, beats 5.37%
class Solution1 {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int count = 0;
        while (!que.empty()) {

            int size = que.size();
            for (int i = 0; i < size; ++i) {
                count++;
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return count;
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
    cout << s.countNodes(root) << endl;

    return 0;
}
