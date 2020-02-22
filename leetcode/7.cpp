#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>

using namespace std;


class Solution2 {
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }

    int reverse1(int x) {
        if ((x > 0 && x > INT_MAX) || (x < 0 && x < INT_MIN) ) {
            return 0;
        }
        bool nagative = false;
        if (x < 0) {
            x *= -1;
            nagative = true;
        }
        int copyx = x;
        int count = 0;
        while (copyx % 10 || copyx / 10) {
            copyx /= 10;
            count++;
        }

        int result = 0;
        while(x % 10 || x / 10) {
            result += (x % 10) * pow(10, count - 1);
            x /= 10;
            count--;
        }

        if (result < 0) {
            // int32 overflow
            return 0;
        }

        return nagative ? -1*result : result;
    }
};

class Solution {
public:
    int reverse(int x) {
        long long ret = 0;

        int n = x;
        while (n) {
            ret = ret * 10 + n % 10;
            n /= 10;
        }

        if ((ret < 0 && ret < INT_MIN) || (ret > 0 && ret > INT_MAX)) {
            return 0;
        }

        return ret;
    }
};




int main(int argc, char* argv[])
{
    Solution sln;
    std::cout<<sln.reverse(123)<<std::endl;
    std::cout<<sln.reverse(-123)<<std::endl;

    std::cout<<sln.reverse(-1235678)<<std::endl;
    std::cout<<sln.reverse(-2147483648)<<std::endl;
    return 0;
}
