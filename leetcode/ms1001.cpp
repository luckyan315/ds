#include <iostream>
#include <vector>

using namespace std;

// 8ms, beats 28.76%
// 11.6MB, beats 100.00%

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        int i = 0;
        int j = 0;
        while (j < n && i <= m + j) {
            if(B[j] < A[i]) {
                // A.insert(A.begin() + i, B[j]);
                insert(A, i, B[j]);
                i++;
                j++;
            } else {
                i++;
            }
        }

        while (j < n) {
            A[i - 1] = B[j];
            i++;
            j++;
        }
    }

    void insert(vector<int>& v, int index, int n) {
        int tmp = 0;
        for (int i = index; i < v.size(); ++i) {
            tmp = v[i];
            v[i] = n;
            n = tmp;
        }
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> a = {1,2,3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    s.merge(a, 3, b, 3);

    for(auto& e : a) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
