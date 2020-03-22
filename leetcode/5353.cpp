#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

// accept
// 比较容易想到的通用方法
// 156ms
// 38.8MB
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int maxi = 0;
        int cur = 0;
        vector<bool> vis(light.size() + 2, false);
        for (int i = 0; i < light.size(); ++i) {
            maxi = std::max(maxi, light[i]);
            vis[light[i]] = true;
            while(vis[cur + 1]) cur++;

            if(cur == maxi) res++;
        }

        return res;
    }
};

// accept
// 84ms, beats 100.00%
// 38.7MB, beats 100.00%
class Solution3 {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int maxcurIndex = -1;
        for (int i = 0; i < light.size(); ++i) {
            if(i == 0 && light[i] == 1) {
                res++;
                maxcurIndex = light[i] - 1;
                continue;
            }
            maxcurIndex = max(maxcurIndex, light[i] - 1);
            if(i == maxcurIndex) res++;

        }
        return res;
    }
};


// 原题题目理解有误, 如果只是 小于亮灯节点 index 所有灯都亮，算一次记录,
// 下面解法是ok， 但题目原意是 所有之前点亮的节点都要变蓝， 下面解法有问题
class Solution2 {
public:
    int numTimesAllBlue(vector<int>& light) {
        auto res = 0;
        vector<bool> vis(light.size(), false);
        for (int i = 0; i < light.size(); ++i) {
            int cur = light[i] - 1;
            int j = 0;
            if(cur == 0) {
                int cnt = 1;
                int k = cur;
                while(vis[++k]) cnt++;
                if(cnt > 1) res++;

                vis[cur] = true;
                continue;
            }
            for (; j < cur; ++j) if(!vis[j]) break;

            if(j == cur) res++;

            vis[cur] = true;
        }

        return res;
    }
};

// accept
// 108ms, beats 100.00%
// 38.6MB, 100.00%
class Solution1 {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int seqSum = 0;
        int resSum = 0;
        for (int i = 0; i < light.size(); ++i) {
            resSum += light[i];
            seqSum += (i + 1);
            if(resSum == seqSum) res++;
        }

        return res;
    }
};

// copy from leetcode
// https://leetcode-cn.com/contest/weekly-contest-179/ranking/
// zqy1018,  problem 2
class Solution_by_leetcode {

public:
    int numTimesAllBlue(vector<int>& light) {
        int cur = 0, ans = 0, maxi = 0;
        vector<bool> vis(light.size() + 2, false);
        for (int x: light){
            vis[x] = true;
            maxi = max(maxi, x);
            while (vis[cur + 1])
                ++cur;
            if (cur == maxi) ++ans;
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    // vector<int> input = {2,1,3,5,4};
    vector<int> input = {3,2,4,1,5};
    // vector<int> input = {4,1,2,3};
    Solution s;
    cout << s.numTimesAllBlue(input) << endl;
    return 0;
}
