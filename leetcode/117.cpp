#include <iostream>
#include <queue>
#include <set>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// accept
// 16ms, beats 85.65%
// 20MB, beats 35.41%
class Solution {
public:
    Node* connect(Node* root) {
        traverse(root);
        return root;
    }

    void traverse(Node* node) {
        if(node == nullptr) return;

        queue<Node*> que;
        set<int> visited;
        que.push(node);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node* cur = que.front();
                que.pop();
                if(i != size - 1) {
                    Node* curNext = que.front();
                    cur->next = curNext;
                }

                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
    }
};


int main(int argc, char *argv[])
{

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    Solution s;
    Node* res = s.connect(node1);
    while (res) {

        Node* cur = res;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;

        res = res->left;
    }

    return 0;
}
