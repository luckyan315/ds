#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// accept, lintcode, https://www.lintcode.com/problem/plus-one-linked-list/my-submissions
class Solution {
public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        // Write your code here
        ListNode* node = new ListNode(0);
        node->next = head;

        ListNode* p = node;
        // mark node which not including 9
        ListNode* t = node;

        while (p) {
            if(p->val != 9) t = p;
            p = p->next;
        }

        t->val += 1;

        ListNode* it = t->next;
        while (it){
            it->val = 0;
            it = it->next;
        }

        return t == node ? node : head;
    }
};

int main(int argc, char *argv[])
{
    vector<int> input = {1, 3, 0};
    ListNode* head = NULL;
    ListNode* cur = NULL;

    for (int i = 0; i < input.size(); ++i) {
        if (i == 0) {
            // first time
            head = new ListNode(input[i]);
            cur = head;
            continue;
        }
        cur->next = new ListNode(input[i]);
        cur = cur->next;
    }

    Solution s;
    ListNode* res = s.plusOne(head);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
