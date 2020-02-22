#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution2 {
public:
    string longestPalindrome(string s) {
        int start, len = 0;
        // abba
        for (int i = 0; i < s.length(); ++i) {
            int l = i;
            int r = i;
            while(r < s.length() - 1 && s[r] == s[r + 1]) {
                r++;
            }
            i = r;

            while(l > 0 && r < s.length() - 1 && s[l-1] == s[r+1]) {
                l--;
                r++;
            }

            if (len < r - l + 1) {
                len = r -l + 1;
                start = l;
            }
        }
        return s.substr(start, len);
    }

    string longestPalindrome1(string s) {
        if (s.length() == 0){
            s = "^$";
            return s;
        }

        string ret = "^";
        for (int i = 0; i < s.length(); ++i) {
            ret += "#";
            ret += s.substr(i, 1);
        }

        ret += "#$";

        vector<int> P(ret.length(), 0);
        int center = 1;
        int max = 0;
        // ^#a#b#a#$
        for (; center < ret.length(); ++center) {
            int delta = 1;
            while(center - delta >= 0 && center + delta < ret.length()) {
                if (ret.at(center - delta) != ret.at(center + delta)) {
                    break;
                }
                delta++;
            }
            P[center] = delta;
            // cout<<"visit: "<<ret[center]<<" index: "<<center<<" value: "<<delta<<endl;
        }


        int maxi = 0;
        for (int i = 0; i < P.size(); ++i) {
            if (max < P[i]) {
                max = P[i];
                maxi = i;
            }
        }

        string result;
        for (int cur = maxi + 1 - max; cur < maxi + max; ++cur) {
            if (ret[cur] == '#') {
                continue;
            }
            result += ret[cur];
        }

        return result;
    }
};

// not accept , sanitizer issue , stack over flow
class Solution3 {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.length() == 1) return s;

        vector<string> ret;
        int i = 0;
        int max = 0;
        for (; i < s.length(); ++i) {
            for (int j = s.length() - 1; j > i; --j) {
                if (max != 0 && j - i + 1 < max) {
                    continue;
                }
                if (s[i] == s[j] && i < j) {
                    int b = i;
                    int e = j;

                    while (s[++b] == s[--e]);

                    if (b >= e) {
                        // find ans
                        max = max < (j -i + 1) ? j - i + 1 : max;
                        ret.push_back(s.substr(i, j -i + 1));
                        break;
                    }
                } else {
                    continue;
                }
            }
        }

        if (ret.size() == 0) {
            return s.substr(0, 1);
        }

        sort(ret.begin(), ret.end(), Solution3::mysort);
        return ret.back();
    }

    static bool mysort (string& a, string& b) {
        return a.length() < b.length();
    }
};

// https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0 || len == 1) {
            return s;
        }
        bool dp[len][len];
        int maxlen = 0;
        int startPos = 0;
        for (int r = 1; r < s.size(); ++r) {
            for (int l = 0; l < r; l++) {
                if (s[l] == s[r] && ( (r - l) <= 2 ||  dp[l + 1][r - 1])) {
                    dp[l][r] = true;
                    if (maxlen < r - l + 1) {
                        maxlen = r - l + 1;
                        startPos = l;
                    }
                } else {
                    dp[l][r] = false;
                }
            }
        }

        if (maxlen == 0) {
            return s.substr(0, 1);
        }

        return s.substr(startPos, maxlen);
    }
};


int main(int argc, char *argv[])
{
    Solution *pSln = new Solution();
    string str(argv[1]);
    cout<<pSln->longestPalindrome(str)<<endl;
    delete pSln;
    return 0;
}
