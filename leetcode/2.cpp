#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* prevh1 = h1;
        ListNode* h2 = l2;
        int carry = 0;
        while (h1 != nullptr && h2 != nullptr) {
            h1->val += h2->val + carry;
            if (h1->val > 9){
                h1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            prevh1 = h1;
            h1 = h1->next;
            h2 = h2->next;
        }

        while (h1 != nullptr) {
            h1->val += carry;
            if (h1->val > 9) {
                h1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            prevh1 = h1;
            h1 = h1->next;
        }

        if (prevh1 != nullptr) {
            prevh1->next = h2;
            h1 = prevh1->next;
        }
        while (h1 != nullptr) {
            h1->val += carry;
            if(h1->val > 9){
                h1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            prevh1 = h1;
            h1 = h1->next;
        }

        if (carry == 1) {
            ListNode* last = new ListNode(1);
            prevh1->next = last;
        }

        return l1;
    }

    ListNode* createLinkedList(int a, int b, int c) {
        ListNode* newa = new ListNode(a);
        ListNode* newb = new ListNode(b);
        newa->next = newb;
        ListNode* newc = new ListNode(c);
        newb->next = newc;
        return newa;
    }

    void print(ListNode* node) {
        while (node != NULL) {
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
    }
};


// Success
// Details
// Runtime: 24 ms, faster than 64.02% of C++ online submissions for Add Two Numbers.
// Memory Usage: 9.9 MB, less than 94.86% of C++ online submissions for Add Two Numbers.

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* const l1, ListNode* const l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* h1prev = NULL;
        int carry = 0;
        while(h1 != NULL && h2 != NULL) {

            h1->val += (h2->val + carry);
            if (h1->val > 9) {
                h1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            h1prev = h1;
            h1 = h1->next;
            h2 = h2->next;
        }

        if (h2 != NULL) {
            h1prev->next = h2;
            h1 = h1prev->next;
        }

        while (h1 != NULL) {
            h1->val += carry;
            if (h1->val > 9) {
                h1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            h1prev = h1;
            h1 = h1->next;
        }

        if (carry == 1) {
            h1prev->next = new ListNode(1);
        }

        return l1;
    }

    ListNode* createLinkedList(int a, int b, int c) {
        ListNode* newa = new ListNode(a);
        ListNode* newb = new ListNode(b);
        newa->next = newb;
        ListNode* newc = new ListNode(c);
        newb->next = newc;
        return newa;
    }

    void print(ListNode* node) {
        while (node != NULL) {
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
    }
};

// Accept Status: Success
// Runtime: 24 ms, faster than 64.02% of C++ online submissions for Add Two Numbers.
// Memory Usage: 9.8 MB, less than 97.71% of C++ online submissions for Add Two Numbers.

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* const l1, ListNode* const l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* h1prev = NULL;
        while(h1 != NULL && h2 != NULL) {

            h1->val += h2->val;

            h1prev = h1;
            h1 = h1->next;
            h2 = h2->next;
        }

        if (h2 != NULL) {
            h1prev->next = h2;
        }

        h1 = l1;
        while (h1 != NULL) {
            if (h1->val > 9) {
                if (h1->next == NULL){
                    h1->next = new ListNode(1);
                } else {
                    h1->next->val += 1;
                }

                h1->val %= 10;
            }
            h1 = h1->next;
        }

        return l1;
    }

    ListNode* createLinkedList(int a, int b, int c) {
        ListNode* newa = new ListNode(a);
        ListNode* newb = new ListNode(b);
        newa->next = newb;
        ListNode* newc = new ListNode(c);
        newb->next = newc;
        return newa;
    }

    void print(ListNode* node) {
        while (node != NULL) {
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
    }
};

int main(int argc, char *argv[])
{
    Solution *pSln = new Solution();

    ListNode* first = pSln->createLinkedList(2,4,3);
    ListNode* second = pSln->createLinkedList(5,6,4);

    // pSln->print(first);

    // pSln->print(second);

    ListNode *result = pSln->addTwoNumbers(first, second);

    pSln->print(result);

    delete pSln;
    return 0;
}
