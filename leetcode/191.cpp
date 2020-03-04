#include <iostream>

// accept
// 8ms, 29.42%
// 8.2MB, 32.22%
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            if((n >> i & 1) == 1 ) cnt++;
        }
        return cnt;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
