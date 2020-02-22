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
// 80ms, 68.94%
// 57.5MB, 12.07%
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> layer;
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                layer.push_back(node->val);
                que.pop();
                vector<Node*> children = node->children;
                if(children.size() == 0) continue;
                for(auto& child : children){
                    que.push(child);
                }
            }
            res.push_back(layer);
        }

        return res;
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
    vector<vector<int>> res = s.levelOrder(root);
    for(auto& line : res){
        for(auto& e : line){
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
