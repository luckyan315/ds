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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};

// 0ms, 100.00%
// 10.2MB, 5.00%
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};


int main(int argc, char *argv[])
{
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = new ListNode(4);
    node1->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* res = s.reverseList(node1);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
