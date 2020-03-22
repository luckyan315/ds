#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// accept
// 4ms, beats 78.10%
// 8.4MB, beats 10.39%
// solution1 基础上 loop 里面简单剪枝
class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; ++i) {
            str += to_string(i);
        }

        int index = 0;
        vector<string> ans;
        string path;
        permutate(str, ans, path, k);
        return ans[k - 1];
    }

    int fac(int n) {
        int res = 1;
        while (n) {
            res *= n--;
        }
        return res;
    }

    bool permutate(string str, vector<string>& ans, string path, int& k) {
        int len = str.length();
        if(len == 1) {
            path += str;
            ans.push_back(path);
            if(ans.size() == k) return true;
            return false;
        }

        for (int i = 0; i < len; ++i) {
            int nFac = fac(len - 1);
            if(k > nFac) {
                k -= nFac;
                continue;
            }
            path.push_back(str[i]);
            string substr;
            for (int j = 0; j < str.length(); ++j) {
                if(i == j) continue;
                substr += str[j];
            }

            if(permutate(substr, ans, path, k)) return true;
            path = path.substr(0, path.length() - 1);
        }

        return false;
    }
};

// accept
// 2468ms, 5.09%
// 272.1MB, 5.13%
class Solution1 {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; ++i) {
            str += to_string(i);
        }

        int index = 0;
        vector<string> ans;
        string path;
        permutate(str, ans, path, k);
        return ans[k - 1];
    }

    bool permutate(string str, vector<string>& ans, string path, int k) {
        if(str.length() == 1) {
            path += str;
            ans.push_back(path);
            if(ans.size() == k) return true;
            return false;
        }
        for (int i = 0; i < str.length(); ++i) {
            path.push_back(str[i]);
            string substr;
            for (int j = 0; j < str.length(); ++j) {
                if(i == j) continue;
                substr += str[j];
            }

            if(permutate(substr, ans, path, k)) return true;
            path = path.substr(0, path.length() - 1);
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // cout << s.fac(3) << endl;
    cout << s.getPermutation(4, 9) << endl;
    return 0;
}
