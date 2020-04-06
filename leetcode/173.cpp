#include <iostream>
#include <unordered_map>
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
// 88ms, beats 17.48%
// 26.3MB, beats 5.31%
class BSTIterator {
public:
    vector<int> arr;
    int cur = 0;
    BSTIterator(TreeNode* root) {
        traverse(root);
    }

    void traverse(TreeNode* root) {
        if(root == nullptr) return;
        if(root->left) traverse(root->left);
        arr.push_back(root->val);
        if(root->right) traverse(root->right);
    }

    /** @return the next smallest number */
    int next() {
        return arr[cur++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char *argv[])
{
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;

    return 0;
}
