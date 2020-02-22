#include <iostream>
#include <vector>

using namespace std;

// accepts
// 4ms, beats 77.60%
// 8.7MB, beats 5.37%
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (++digits[i] %= 10) return digits;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// accepts
// 8ms, beats 26.02%
// 9MB, beats 5.37%
class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }

        if (i != -1) {
            digits[i] += 1;
        } else {
            // push 1st node with 1
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {1,2,4};
    vector<int> res = s.plusOne(input);
    for (auto& e : res) {
        cout << e << " ";
    }
    cout<<endl;
    return 0;
}
