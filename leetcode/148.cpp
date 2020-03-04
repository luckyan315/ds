#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 920ms, 6.84%
// 16.5MB, 23.55%
// 插入排序 T:O(n^2)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);

        while (head) {
            ListNode* cur = dummy->next;
            ListNode* pre = dummy;
            while (cur) {
                // insert head val
                if(head->val <= cur->val) {
                    pre->next = new ListNode(head->val);
                    pre = pre->next;
                    pre->next = cur;
                    break;
                }
                pre = cur;
                cur = cur->next;
            }

            if(cur == nullptr) {
                pre->next = new ListNode(head->val);
            }

            head = head->next;
        }

        return dummy->next;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode* node1 = new ListNode(-1);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(0);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* res = s.sortList(node1);
    while(res) {
        cout << res->val << " ";
        res = res->next;
    }

    cout << endl;
    return 0;
}
