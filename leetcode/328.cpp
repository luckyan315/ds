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
// 20ms, 37.97%
// 12.1MB, 5.09%
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr ||
           head->next->next == nullptr) return head;

        ListNode* odd = head;

        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

int main(int argc, char *argv[])
{
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(5);

    Solution s;
    ListNode* res = s.oddEvenList(head);
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
