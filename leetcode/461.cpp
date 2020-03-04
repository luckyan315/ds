#include <iostream>
#include <vector>

using namespace std;

// accept
// 4ms, 64.80%
// 8.3MB, 5.24%
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if(((x >> i) & 1) != ((y >> i) & 1)) ans++;
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.hammingDistance(3, 1) << endl;
    return 0;
}
