#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

// 196ms, 100.00%
// 59.3MB, 100.00%
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n <= 2 || leftChild.size() <= 2 || rightChild.size() <= 2) return false;

        map<int, pair<int, int>> bt;
        for (int i = 0; i < leftChild.size(); ++i){
            bt.insert({i, {leftChild[i], rightChild[i]}});
        }

        int cnt = 0;
        set<int> isVisited;
        int res = traverse(0, bt, isVisited, cnt);
        // cout << "cout : " << cnt << endl ;
        return res ? cnt == n : res;
    }

    bool traverse(int node, map<int, pair<int, int>>& bt, set<int>& isVisited, int& cnt) {

        if(isVisited.count(node) > 0) return false;

        isVisited.insert(node);
        cnt++;

        if(bt[node].first != -1)
            if(!traverse(bt[node].first, bt, isVisited, cnt)) return false;

        if(bt[node].second != -1)
            if(!traverse(bt[node].second, bt, isVisited, cnt)) return false;

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // int n = 6;
    // vector<int> left = {1, -1, -1, 4, -1, -1};
    // vector<int> right = {2, -1, -1, 5, -1, -1};

    int n = 4;
    vector<int> left = {1, -1, 3, -1};
    vector<int> right = {2, 3, -1, -1};

    // int n = 4;
    // vector<int> left = {1, -1, 3, -1};
    // vector<int> right = {2, -1, -1, -1};

    cout << s.validateBinaryTreeNodes(n, left, right) << endl;
    return 0;
}
