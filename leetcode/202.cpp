#include <iostream>
#include <cmath>

using namespace std;

// accept
// 0ms, 100.00%
// 8.1MB, 68.50%
class Solution {
public:
    int calculate(int n) {
        int sum  = 0;
        // cout << "n: " << n ;
        while(n > 0){
            int tmp = n % 10;
            sum += pow(tmp, 2);
            n /= 10;
        }
       // cout  << " sum: " << sum << endl;
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = calculate(slow);
            fast = calculate(fast);
            fast = calculate(fast);
        } while(slow != fast);

        return slow == 1;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int num = argc == 2 ? atoi(argv[1]) : 19;
    cout << s.isHappy(num) << endl;
    return 0;
}
