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

// accept
// 4ms, 98.25%
// 16.7MB, 5.16%
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* prev = head;

        while (l1 && l2) {
            if(l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }

            prev = prev->next;
        }

        prev->next = l1 == nullptr ? l2 : l1;

        return head->next;
    }
};


int main(int argc, char *argv[])
{
    ListNode* l1a = new ListNode(1);
    ListNode* l1b = new ListNode(2);
    ListNode* l1c = new ListNode(4);
    l1a->next = l1b;
    l1b->next = l1c;

    ListNode* l2a = new ListNode(1);
    ListNode* l2b = new ListNode(3);
    ListNode* l2c = new ListNode(4);
    l2a->next = l2b;
    l2b->next = l2c;

    Solution s;
    ListNode* head = s.mergeTwoLists(l1a, l2a);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
