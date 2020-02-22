#include <iostream>
#include <vector>
#include <set>

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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        while (head) {
            if (s.count(head) != 0) {
                return head;
            }
            s.insert(head);
            head = head->next;
        }

        return NULL;
    }
};

// accept
// 32ms, beats 7.65%
// 12.2MB, beats 5.09%
class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        while (head) {
            if (s.count(head) != 0) {
                return head;
            }
            s.insert(head);
            head = head->next;
        }

        return NULL;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr = {3,2,0,4};
    ListNode * head = NULL;
    ListNode * cur = NULL;

    // mock dup node
    ListNode * dup = NULL;
    int dupNum = 4;

    for (auto& e : arr) {
        ListNode* node = new ListNode(e);
        if (e == dupNum) {
            dup = node;
        }
        if (head == NULL) {
            head = node;
            cur = head;
            continue;
        }
        cur->next = node;
        cur = cur->next;
    }

    // append dup node
    cur->next = dup;

    cout << s.detectCycle(head)->val << endl;

    return 0;
}
