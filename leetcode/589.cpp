#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// accept
// 72ms, 84.98%
// 57.1MB, 19.23%
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == nullptr) return vector<int>();
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(Node* node, vector<int>& res) {
        if(node == nullptr) return;
        res.push_back(node->val);

        for(auto& node : node->children){
            traverse(node, res);
        }
    }
};

int main(int argc, char *argv[])
{
    Node* five = new Node(5);
    Node* six = new Node(6);
    Node* three = new Node(3, vector<Node*>({five, six}));
    Node* two = new Node(2);
    Node* four = new Node(4);
    Node* root = new Node(1, vector<Node*>({three, two, four}));

    Solution s;
    vector<int> res = s.preorder(root);

    for(auto& e : res){
        cout << e << " ";
    }
    cout << endl;


    return 0;
}
