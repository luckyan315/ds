#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

// accept
// 16ms, beast 17.89%
// 7.2MB, beats 100.00%
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {

            while (!st.empty() && height[st.top()] < height[i]) {
                // top: smallest value index
                int top = st.top();
                st.pop();
                while (!st.empty() && height[top] == height[st.top()]) {
                    st.pop();
                }

                // cout << "cur index: " << i  << " stack top: " << st.top() << endl;
                if(!st.empty()) {
                    sum += (min(height[st.top()], height[i]) - height[top]) * (i - st.top() - 1);
                }
            }

            st.push(i);
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(input) << endl;
    return 0;
}
