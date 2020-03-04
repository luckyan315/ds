#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// accept
// 8ms, 91.58%
// 13.9MB, 5.11%
class Solution {
public:
    static bool cmp(string& a, string& b) {
        // cout << "compare   a: " << a << "  b: " << b << endl;
        // cout << "a + b: " << a + b << " b + a: " << b + a << endl;
        int lena = a.length();
        int lenb = b.length();
        for(int i = 0; i < lena + lenb; ++i ) {
            char chab = i < lena ? a[i] : b[i - lena];
            char chba = i < lenb ? b[i] : a[i - lenb];
            if(chab == chba) continue;
            return chab > chba;
        }

        return false;
    }


    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";

        if(all_of(nums.begin(), nums.end(), [](int x) { return x == 0;})) return string("0");


        vector<string> strnums;
        for(auto& e : nums) {
            strnums.push_back(to_string(e));
        }

        sort(strnums.begin(), strnums.end(), cmp);

        string res;
        for(auto& str : strnums){
            res += str;
        }
        return res;
    }
};

// accept
// 12ms, 70.75%
// 13.8MB, 5.11%
class Solution1 {
public:
    static bool cmp(string& a, string& b) {
        // cout << "compare   a: " << a << "  b: " << b << endl;
        // cout << "a + b: " << a + b << " b + a: " << b + a << endl;
        return a + b > b + a;
    }


    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";

        if(all_of(nums.begin(), nums.end(), [](int x) { return x == 0;})) return string("0");


        vector<string> strnums;
        for(auto& e : nums) {
            strnums.push_back(to_string(e));
        }

        sort(strnums.begin(), strnums.end(), cmp);

        string res;
        for(auto& str : strnums){
            res += str;
        }
        return res;
    }
};



int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {11, 22, 33};
    cout << s.largestNumber(input) << endl;
    return 0;
}
