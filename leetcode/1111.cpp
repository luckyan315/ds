#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// accept
// 4ms, beats 88.31%
// 7.6MB, beats 100.00%
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        if(seq.length() == 0) return vector<int>();
        vector<int> res;
        stack<char> st;
        for (int i = 0; i < seq.length(); ++i) {
            char ch = seq[i];
            if(ch == '(') {
                res.push_back(st.size() % 2);
                st.push(ch);
            } else {
                st.pop();
                res.push_back(st.size() % 2);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> res = s.maxDepthAfterSplit("(()())");
    for (auto& e : res) {
        cout << e << " ";
    }
    return 0;
}
