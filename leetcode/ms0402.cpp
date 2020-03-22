#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

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

// accepts
// 28ms, 26.69%
// 25.6MB, 100.00%
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        if(nums.size() == 2) {
            TreeNode* root = new TreeNode(nums[1]);
            root->left = new TreeNode(nums[0]);
            return root;
        }

        int mid = nums.size() / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        vector<int> lv(nums.begin(), nums.begin() + mid);
        node->left = sortedArrayToBST(lv);

        vector<int> rv(nums.begin() + (mid + 1), nums.end());
        node->right = sortedArrayToBST(rv);
        return node;
    }

    void traverse(TreeNode* node) {
        if(node == nullptr) return;

        cout << node->val << " ";
        if(node->left) traverse(node->left);
        if(node->right) traverse(node->right);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {-10, -3, 0, 5, 9};
    TreeNode* node = s.sortedArrayToBST(input);
    s.traverse(node);
    cout << endl;
    return 0;
}
