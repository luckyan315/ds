#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        if(n == 0) return "";
        string res;
        if(n % 2 == 1) {
            for (int i = 0; i < n; ++i) {
                res += 'a';
            }
        } else {
            int ogg = n - 1;
            for (int i = 0; i < ogg; ++i) {
                res += 'a';
            }
            res += "b";
        }
        return res;
    }
};
