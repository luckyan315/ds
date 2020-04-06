#include <iostream>
#include <stack>
#include <string>

using namespace std;

// accept
// 4ms, beats 66.05%
// 6.4MB, beats 100.00%
class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        if(s.length() == 1) return false;
        stack<char> st;
        for (auto& ch : s) {
            if(ch == '{' || ch == '[' || ch == '(') {
                st.push(ch);
            } else {
                switch(ch) {
                case '}':
                    if(!st.empty() && st.top() == '{') st.pop();
                    else return false;
                    break;
                case ']':
                    if(!st.empty() && st.top() == '[') st.pop();
                    else return false;
                    break;
                case ')':
                    if(!st.empty() && st.top() == '(') st.pop();
                    else return false;
                    break;
                }
            }
        }
        return st.empty();
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.isValid(argv[1]) << endl;
    return 0;
}
