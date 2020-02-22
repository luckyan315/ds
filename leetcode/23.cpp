#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); ++i) {
            ListNode* cur = lists[i];
            while (nullptr != cur) {

                merge2head(&head, cur);

                cur = cur->next;
            }
        }

        return head;
    }

    void merge2head(ListNode** addrHeadNode, ListNode* cur) {
        ListNode* newHead = new ListNode(cur->val);
        if (*addrHeadNode == nullptr) {
            *addrHeadNode = newHead;
            return;
        }
        ListNode* iterPtr = *addrHeadNode;
        ListNode* preNode = nullptr;

        while (iterPtr != nullptr) {
            if (cur->val <= iterPtr->val) {
                if (preNode == nullptr) {
                    newHead->next = *addrHeadNode;
                    *addrHeadNode = newHead;
                } else {
                    preNode->next = newHead;
                    newHead->next = iterPtr;
                }
                break;
            }
            preNode = iterPtr;
            iterPtr = iterPtr->next;
        }

        if (iterPtr == nullptr) {
            preNode->next = newHead;
        }
    }

    ListNode* createNode(vector<int> arr) {
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for (int i = 1; i < arr.size(); ++i){
            ListNode* newNode = new ListNode(arr[i]);
            cur->next = newNode;
            cur = cur->next;
        }

        return head;
    }
};

// accepted
// 172ms/31.26%,  11.4MB/77.56%

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); ++i) {
            ListNode* cur = lists[i];
            while (nullptr != cur) {

                merge2head(&head, cur);

                cur = cur->next;
            }
        }

        return head;
    }

    void merge2head(ListNode** addrHeadNode, ListNode* cur) {
        ListNode* newHead = new ListNode(cur->val);
        if (*addrHeadNode == nullptr) {
            *addrHeadNode = newHead;
            return;
        }
        ListNode* iterPtr = *addrHeadNode;
        ListNode* preNode = nullptr;



        while (iterPtr != nullptr) {
            if (cur->val <= iterPtr->val) {
                if (preNode == nullptr) {
                    newHead->next = *addrHeadNode;
                    *addrHeadNode = newHead;
                } else {
                    preNode->next = newHead;
                    newHead->next = iterPtr;
                }
                break;
            }
            preNode = iterPtr;
            iterPtr = iterPtr->next;
        }

        if (iterPtr == nullptr) {
            preNode->next = newHead;
        }

    }

    ListNode* createNode(vector<int> arr) {
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for (int i = 1; i < arr.size(); ++i){
            ListNode* newNode = new ListNode(arr[i]);
            cur->next = newNode;
            cur = cur->next;
        }

        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    ListNode* h1 = s.createNode(vector<int>{1,4,5});
    ListNode* h2 = s.createNode(vector<int>{1,3,4});
    ListNode* h3 = s.createNode(vector<int>{2,6});

    vector<ListNode*> lists;
    lists.push_back(h1);
    lists.push_back(h2);
    lists.push_back(h3);

    ListNode* mh = s.mergeKLists(lists);

    while(mh != nullptr) {
        cout<< mh->val << " ";
        mh = mh->next;
    }
    return 0;
}
