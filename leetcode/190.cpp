#include <iostream>

using namespace std;

// accept
// 4ms, beats 81.51%
// 8MB, beats 75.05%
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long rev = 0;
        for (int i = 0; i < 32; i++) {
            rev |= ((n >> i) & 1) << (31 - i);
        }
        return (uint32_t)rev;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    cout << s.reverseBits(43261596) << endl;
    return 0;
}
