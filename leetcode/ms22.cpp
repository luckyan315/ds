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
// 0ms, beats 100.00%
// 10.4MB, beats 100.00%
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }

        len = len - k;
        while(--len){
            head = head->next;
        }
        return head;
    }
};
