#include <iostream>
#include <regex>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0) {
            return 0;
        }
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }

        str = str.substr(i);
        if (str.length() > 0 && str[0] == '+') {
            str = str.substr(1);
            if (str.length() > 0 && str[0] == '-') {
                return 0;
            }
        }
        i = 0;
        int bNagative = false;
        if (str[0] == '-') {
            bNagative = true;
            i++;
        }

        while (str[i] >= '0' && str[i] <= '9') {
            i++;
        }

        if ((bNagative && i == 1) || i == 0) {
            return 0;
        }

        int numSize = i;
        long long num = getNum(str, numSize, bNagative);
        if (num <= INT_MIN) {
            return INT_MIN;
        }

        if (num >= INT_MAX) {
            return INT_MAX;
        }

        return num;
    }

    long long getNum(string& str, int numSize, bool bNagative) {

        string tmp = str;
        // cout << "string: " << str << " numSize: " << numSize << endl;
        if (bNagative) {
            tmp = tmp.substr(1);
            numSize = numSize - 1;
        }

        int i = 0;
        while (tmp[i] == '0') {
            i++;
        }
        tmp = tmp.substr(i);
        numSize -= i;

        if (numSize > 10) {
            return bNagative ? INT_MIN : INT_MAX;
        }

        long long ret = 0;
        i = 0;
        while (i < numSize) {
            ret += (tmp[i] - '0') * pow(10, numSize - i - 1);
            i++;
        }
        return bNagative ? -1 * ret : ret;
    }
};

class Solution1 {
public:
    int myAtoi(string str) {
        long long ret = 0;
        string s = stripSpacePrefix(str);

        if (!regex_match (s, regex("^[-]?[1-9][0-9]*.*"))) return 0;

        int i = 0;

        if (s[0] == '-') {
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9') i++;

        s = s.substr(0, i - 1);

        for (int j = 0; j < s.length(); ++j) {

        }

        return ret;
    }

    string stripSpacePrefix(string& str) {
        int i = 0;
        while (str[i++] == ' ');

        if (i == str.length() || i == 0) return "";

        return str.substr(i - 1);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.myAtoi(argv[1])<<endl;
    return 0;
}
