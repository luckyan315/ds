#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// accept
// 48ms, beats 11.27%
// 32.2MB, beats 5.02%
class Solution {
public:
    int maxcnt = INT_MIN;
    set<int> cache;
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        if(root->left == nullptr && root->right == nullptr) return vector<int>(1, root->val);
        map<int, int> mp;
        vector<int> res;
        traverse(root, mp, res);
        return res;
    }

    void traverse(TreeNode* node, map<int, int>& mp, vector<int>& res) {
        if(node == nullptr) return;
        if(node->left) traverse(node->left, mp, res);

        if(mp.count(node->val) == 0) {
            mp[node->val] = 0;
        }

        mp[node->val]++;
        if(mp[node->val] > maxcnt) {
            cache.clear();
            res.clear();
            cache.insert(node->val);
            res.push_back(node->val);
            maxcnt = mp[node->val];

        } else if(mp[node->val] == maxcnt) {
            if(cache.count(node->val) == 0) {
                cache.insert(node->val);
                res.push_back(node->val);
            }
        }

        if(node->right) traverse(node->right, mp, res);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);

    // root->right->left = new TreeNode(2);

    vector<int> res = s.findMode(root);
    for(auto& e : res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
