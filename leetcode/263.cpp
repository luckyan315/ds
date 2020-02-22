#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// accept
// 12ms, 25.09%
// 8.3MB, 5.4%
class Solution1 {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        if(num == 1) return true;
        // 只包含2,3,5 因子就是丑数
        vector<int> v = {2,3,5};

        return trydivide(num, v);
    }

    bool trydivide(int num, vector<int>& v) {
        if(num == 1) return true;
        for(auto& e : v) {
            if(num % e == 0) {
                return trydivide(num / e, v);
            }
        }
        return false;
    }
};

// accept
// 8ms, 25.09%
// 8MB, 49.93%
class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        if(num == 1) return true;
        // 只包含2,3,5 因子就是丑数
        vector<int> v = {2,3,5};

        return trydivide(num, v);
    }

    bool trydivide(int num, vector<int>& v) {
        int tmp = num;
        while(tmp > 1){
            int prev = tmp;
            for(auto& e : v) {
                if(tmp % e == 0) {
                    tmp /= e;
                }
            }
            if(tmp == prev) return false;
        }

        return tmp == 1;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int num = argc == 2 ? atoi(argv[1]) : 6;
    cout << s.isUgly(num) << endl;
    return 0;
}
