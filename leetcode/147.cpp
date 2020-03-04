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
// 52ms, 48.94%
// 11.6MB, 5.11%
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy->next;

        ListNode* newHead = new ListNode(-1);

        while (cur) {
            ListNode* curNew = newHead->next;
            ListNode* preNew = newHead;

            while (curNew) {
                if(cur->val < curNew->val) {
                    preNew->next = new ListNode(cur->val);
                    preNew = preNew->next;
                    preNew->next = curNew;
                    break;
                }
                if(curNew) {
                    preNew = curNew;
                    curNew = curNew->next;
                }
            }

            if(curNew == nullptr) {
                preNew->next = new ListNode(cur->val);
            }

            cur = cur->next;
        }

        return newHead->next;
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

    ListNode* res = s.insertionSortList(node1);
    while(res) {
        cout << res->val << " ";
        res = res->next;
    }

    cout << endl;
    return 0;
}
