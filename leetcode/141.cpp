#include <iostream>
#include <set>
#include <vector>

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
// 12ms, beats 83.98%
// 9.9MB, beats 20.56%
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;

        while ((slow && slow->next) && (fast && fast->next && fast->next->next)) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                return true;
            }


        }
        return false;
    }
};


// accept
// 28ms, beats 10.57%
// 12.3MB, beats 5.10%
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        bool ret = false;
        set<ListNode*> s;
        while (head) {
            if (s.count(head) != 0) {
                ret = true;
                break;
            }
            s.insert(head);
            head = head->next;
        }

        return ret;
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
    int dupNum = 3;

    for (auto& e : arr) {
        ListNode* node = new ListNode(e);
        if (dupNum == 3) {
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

    cout << s.hasCycle(head) << endl;
    return 0;
}
