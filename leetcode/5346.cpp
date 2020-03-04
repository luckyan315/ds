#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };w
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 52ms, 100.00%
// 34.9MB, 100.00%
class Solution {
public:
    // match subnodes (including match from first node )
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;

        return isSub(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    // match from first node
    bool isSub(TreeNode* root, ListNode* head) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;

        // cout << "visit node: " << root->val << " head: " << head->val << endl;

        if(root->val != head->val) {
            return false;
        }

        return isSub(root->left, head->next) || isSub(root->right, head->next);
    }
};

int main(int argc, char *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(6);

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node4l = new TreeNode(4);
    TreeNode* node4r = new TreeNode(4);
    TreeNode* node2r = new TreeNode(2);
    TreeNode* node2l = new TreeNode(2);

    node1->left = node4l;
    node1->right = node4r;

    node4l->right = node2r;
    node4r->left = node2l;

    TreeNode* node6 = new TreeNode(6);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node11 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);

    node2l->left = node6;
    node2l->right = node8;
    node8->left = node11;
    node8->right = node3;

    Solution s;
    cout << s.isSubPath(head, node1) << endl;

    return 0;
}
