#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

// accept
// 16ms, beats 32.34%
// 10.7MB, beats 7.95%
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>();
        vector<vector<int>> res;

        vector<int> path;
        permuteNext(res, nums, path);
        return res;
    }

    void permuteNext(vector<vector<int>>& res, vector<int>& nums, vector<int>& path) {
        if(nums.size() == 0) return;

        if(nums.size() == 1) {
            path.push_back(nums.back());
            res.push_back(path);
            return;
        }



        for (int i = 0; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            vector<int> nextpath(path.begin(), path.end());
            vector<int> nextnums(nums.begin(), nums.end());
            nextnums.erase(nextnums.begin() + i);
            permuteNext(res, nextnums, nextpath);
            path.pop_back();
        }
    }
};

class Solution3 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        permuteFromPos(nums, 0, ans);

        return ans;
    }

    void permuteFromPos(vector<int>& nums, int pos, vector<vector<int>>& ans) {
        if (pos == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }

        for (int i = pos; i < nums.size(); ++i) {
            swap(nums[i], nums[pos]);
            permuteFromPos(nums, pos + 1, ans);
            swap(nums[i], nums[pos]);
        }
    }
};

// 24ms/击败44.09%,  10.5MB/击败7.61%
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>* retArr = new vector<vector<int>>();

        vector<int> empty;
        list<int> left(nums.begin(), nums.end());
        solve(empty, left, *retArr);

        return *retArr;
    }

    void solve (vector<int>& numsResolved, list<int>& numsLeft, vector<vector<int>>& out) {
        if (numsLeft.size() == 1) {
            numsResolved.push_back(numsLeft.back());
            out.push_back(numsResolved);
            return;
        }

        for (int i = 0; i < numsLeft.size(); ++i) {
            vector<int>* pNewArray = new vector<int>(numsResolved.begin(), numsResolved.end());
            list<int> newLeft(numsLeft.begin(), numsLeft.end());

            list<int>::iterator it = newLeft.begin();
            std::advance(it, i);
            pNewArray->push_back(*it);
            newLeft.erase(it);
            solve(*pNewArray, newLeft, out);
        }
    }
};

// 44ms/击败5.32%, 10.6MB/击败6.82%,
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>* retArr = new vector<vector<int>>();

        vector<int> empty;
        solve(empty, nums, *retArr);

        return *retArr;
    }

    void solve (vector<int>& numsResolved, vector<int> numsLeft, vector<vector<int>>& out) {
        if (numsLeft.size() == 1) {
            numsResolved.push_back(numsLeft[0]);
            out.push_back(numsResolved);
            return;
        }

        for (int i = 0; i < numsLeft.size(); ++i) {
            vector<int>* pNewArray = new vector<int>(numsResolved.begin(), numsResolved.end());
            vector<int>* pNewLeft = new vector<int>(numsLeft.begin(), numsLeft.end());
            pNewArray->push_back(numsLeft[i]);
            pNewLeft->erase(pNewLeft->begin() + i);
            solve(*pNewArray, *pNewLeft, out);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr={1,2,3};
    vector<vector<int>> ret;
    ret = s.permute(arr);

    for (auto &v : ret) {
        for (auto &e : v) {
            cout<<e;
        }
        cout<<"\n";
    }

    return 0;
}
