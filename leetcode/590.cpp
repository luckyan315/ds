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
// 104ms, 34.87%
// 57.1MB, 17.54%
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr) return vector<int>();
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(Node* node, vector<int>& res) {
        if(node == nullptr) return;

        for(auto& e : node->children){
            traverse(e, res);
        }
        res.push_back(node->val);
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
    vector<int> res = s.postorder(root);

    for(auto& e : res){
        cout << e << " ";
    }
    cout << endl;


    return 0;
}
