#include <iostream>
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
// 12ms, 53.40%
// 11MB, 5.10%
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = getLength(root);
        if(len == 0) return vector<ListNode*>(k, nullptr);
        int eleSize = len / k;

        vector<ListNode*> res;

        ListNode* cur = root;
        int left = len % k;
        while(cur){
            if(left-- > 0) {
                cur = adv(cur, eleSize + 1, res);
            } else {
                cur = adv(cur, eleSize, res);
            }
        }
        while((int)res.size() < k) res.push_back(nullptr);
        return res;
    }

    ListNode* adv(ListNode* cur, int eleSize, vector<ListNode*>& res) {
        res.push_back(cur);
        ListNode* prev = cur;
        while (eleSize--) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        return cur;
    }

    int getLength(ListNode* node) {
        int res = 0;
        while(node) {
            res++;
            node = node->next;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (int i = 1; i <= 4; i++) {
        if(head == nullptr) {
            head = new ListNode(1);
            cur = head;
        } else {
            cur->next = new ListNode(i);
            cur = cur->next;
        }
    }

    Solution s;
    int k = argc == 2 ? atoi(argv[1]) : 5;
    vector<ListNode*> res = s.splitListToParts(head, k);
    for(auto& e : res){
        while(e){
            cout << e->val << " ";
            e = e->next;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
