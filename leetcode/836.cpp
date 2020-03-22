#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<vector<int>> rect;
        rect.push_back({rec2[0], rec2[1]});
        rect.push_back({rec2[0], rec2[3]});
        rect.push_back({rec2[2], rec2[3]});
        rect.push_back({rec2[2], rec2[1]});

        for (int i = 0; i < 4; ++i) {
            if(rect[i][0] > rec1[0] && rect[i][0] < rec1[2] &&
               rect[i][1] > rec1[1] && rect[i][1] < rec1[3]){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
