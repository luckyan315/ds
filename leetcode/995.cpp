#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {

    }
};


int main(int argc, char *argv[])
{
    vector<int> input({0,0,0,1,0,1,1,0});
    int k = 3;
    vector<int> mask(input.size(), 0);

    int i = 0;

    while (i < input.size()) {
        int zeroCnt = 0;
        int oriIndex = i;
        while (i < input.size() && input[i++] == 0 ) {
            zeroCnt++;
        }

        while (zeroCnt && oriIndex < input.size()) {
            mask[oriIndex++] = zeroCnt--;
        }
    }

    for (auto& e : mask) {
        cout << e << " ";
    }
    cout << endl;


// Solution s;
    // s.minKBitFlips(input, k);

    return 0;
}
