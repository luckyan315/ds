#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// accept
// bfs
// 388ms, 100.00%
// 119.4MB, 100.00%
class Solution {
public:
    int ans = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            if(manager[i] == -1) continue;
            graph[manager[i]].push_back(i);
        }
        visit(headID, graph, manager, 0, informTime);
        return ans;
    }

    void visit(int id, vector<vector<int>>& graph, vector<int>& manager, int time, vector<int>& informTime) {
        if(informTime[id] == 0) {
            ans = std::max(time, ans);
            return;
        }

        for (auto& child : graph[id]) {
            visit(child, graph, manager, time + informTime[id], informTime);
        }
    }
};

// accept
// 剪枝: 如果非叶子节点 跳过
// 604ms
// 87.8MB
class Solution2 {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = informTime[headID];
        for (int i = 0; i < n; ++i) {
            if(informTime[i] != 0) continue;
            int curInformTime = 0;
            int curi = i;
            while (curi != headID) {
                curInformTime += informTime[curi];
                curi = manager[curi];
            }
            maxTime = std::max(maxTime, curInformTime + informTime[headID]);
        }
        return maxTime;
    }
};

// accept
// 1304ms
// 87.8MB
class Solution1 {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = informTime[headID];
        for (int i = 0; i < manager.size(); ++i) {
            int curInformTime = 0;
            int curi = i;
            while (curi != headID) {
                curInformTime += informTime[curi];
                curi = manager[curi];
            }
            maxTime = std::max(maxTime, curInformTime + informTime[headID]);
        }
        return maxTime;
    }
};

class Solution_bfs_timeout {
public:
    int ans = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        visit(headID, manager, 0, informTime);
        return ans;
    }

    void visit(int id, vector<int>& manager, int time, vector<int>& informTime) {
        if(informTime[id] == 0) {
            ans = std::max(time, ans);
            return;
        }

        vector<int> children;
        for (int i = 0; i < manager.size(); i++) {
            if(manager[i] == id) {
                children.push_back(i);
            }
        }

        for (auto& child : children) {
            visit(child, manager, time + informTime[id], informTime);
        }
    }
};

// 参考leetcode 题解, 简单的 bfs
// 主要参考原因： 自己写的 bfs 总是超时, 原因是 没有构建图， 每次层次遍历子节点时候 重新计算
// children , 借鉴该思路， 先构建图尝试
// https://leetcode-cn.com/problems/time-needed-to-inform-all-employees/solution/yong-you-xiang-tu-biao-shi-shu-di-gui-si-xiang-dfs/
class Solution_copy_from_leetcode {
public:
    int dfs(vector<vector<int>>& G, vector<int>& informTime, int s)
    //计算员工s（s为源点source之意）通知所有属下所需的时间
    {
        if(G[s].size() == 0)
            return 0;
        int res = 0;
        for(int i=0; i<G[s].size(); i++)
            res = max(dfs(G, informTime, G[s][i]) + informTime[s], res);
        return res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> G(n); //反映等级的有向图
        for(int i=0; i<n; i++) //构建有向图，如果i有人manager[i]管，则从manager[i]到i引一条边
        {
            if(i == headID) continue; //如果是经理，则没人管
            G[manager[i]].push_back(i);
        }
        return dfs(G, informTime, headID);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // int n = 6;
    // int headID = 2;
    // vector<int> manager = {2,2,-1,2,2,2};
    // vector<int> informTime = {0, 0, 1, 0, 0, 0};

    int n = 7;
    int headID = 6;
    vector<int> manager = {1, 2, 3, 4, 5, 6, -1};
    vector<int> informTime = {0, 6, 5, 4, 3, 2, 1};

    // int n = 4;
    // int headID = 2;
    // vector<int> manager = {3, 3, -1, 2};
    // vector<int> informTime = {0, 0, 162, 914};

    cout << s.numOfMinutes(n, headID, manager, informTime) << endl;
    return 0;
}
