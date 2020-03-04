#include <iostream>
#include <vector>
#include <map>

using namespace std;

// accept
// 16ms, beats 16.98%
// 12.7MB, beats 5.30%
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (int i = 0; i < nums1.size(); ++i) {
            if(mp.count(nums1[i]) > 0) mp[nums1[i]]++;
            else mp[nums1[i]] = 1;
        }

        vector<int> res;
        for(int j = 0; j < nums2.size(); ++j) {
            int e = nums2[j];
            if(mp.count(e) > 0 && mp[e] > 0) {
                res.push_back(e);
                mp[e]--;
            }
        }

        return res;
    }
};

// accept
// 16ms, beats 16.95%
// 13.3MB, beats 5.30%
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
        map<int, int> mp;
        for (int i = 0; i < nums1.size(); ++i) {
            mp[nums1[i]] += 1;
        }

        vector<int> res;
        for(int j = 0; j < nums2.size(); ++j) {
            int e = nums2[j];
            if(mp[e] > 0) {
                res.push_back(e);
                mp[e] -= 1;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{

    Solution s;
    // vector<int> inputs = {1,2,2,1};
    // vector<int> inputs2 = {2,2};

    vector<int> inputs = {54,93,21,73,84,60,18,62,59,89,83,89,25,39,41,55,78,27,65,82,94,61,12,38,76,5,35,6,51,48,61,0,47,60,84,9,13,28,38,21,55,37,4,67,64,86,45,33,41};
   vector<int> inputs2 = {17,17,87,98,18,53,2,69,74,73,20,85,59,89,84,91,84,34,44,48,20,42,68,84,8,54,66,62,69,52,67,27,87,49,92,14,92,53,22,90,60,14,8,71,0,61,94,1,22,84,10,55,55,60,98,76,27,35,84,28,4,2,9,44,86,12,17,89,35,68,17,41,21,65,59,86,42,53,0,33,80,20};

    // vector<int> inputs = {4,9,5};
    // vector<int> inputs2 = {9,4,9,8,4};

    vector<int> res = s.intersect(inputs, inputs2);
    for(auto& e : res){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
