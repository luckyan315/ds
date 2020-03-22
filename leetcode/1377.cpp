#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solutionxx {
public:
double dfs(map<int, vector<int>>& m, vector<int>& a, int i, int t, int target){
        if (i==target && t==0) //正好跳到，蛙生圆满
            return 1;
        if (t == 0) //步数没了还没跳到，蛙生终结
            return 0;

        a[i]=1;
        double res = 0, count = 0;
        for(int p : m[i]){
            if (a[p]) //跳过的点，pass
                continue;
            res += dfs(m, a, p, t-1, target);
            count++; //能跳的点数+1
        }

        a[i]=0;
        if(count==0)
            return dfs(m, a, i, t-1, target); //无处可去，原地跳

        return res / count;

    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        map<int, vector<int>> m;
        vector<int> a(n+1,0);
        for(auto& e : edges) { //建图
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        return dfs(m, a, 1, t, target);
    }
};



class Solution_ {
public:
    double frogJumpDFS(vector<vector<int>>& adj, vector<int>& visited, int c, int t, int target)
    {
        // 时间结束，青蛙刚好在target点
        // 时间没结束，但是青蛙不能跳了，也就是在某个节点没有子节点了
        int sz = adj[c].size();
        if (sz == 0) {
            return c == target ? 1 : 0;
        }
        if (t == 0 || (sz == 1 && visited[adj[c][0]] == 1)) {
            if (c == target) return 1;
            return 0;
        }
        double p = 1.0 / (c == 1 ? sz : sz - 1);
        double pp = 0;
        for (int i =  0; i < adj[c].size(); i++) {
            if (visited[adj[c][i]] == 1) continue;
            visited[adj[c][i]] = 1;
            pp = max(pp, frogJumpDFS(adj, visited, adj[c][i], t-1, target));
        }
        return p * pp;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // 邻接表
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n+1, 0);
        visited[1] = 1;
        return frogJumpDFS(adj, visited, 1, t, target);
    }
};

// 32ms, 100.00%
// 15.8MB, 100.00%
class Solution {
public:
    struct Node {
        int value;
        int time;
        double ratio;

        Node(int v, int t, double p) : value(v), time(t), ratio(p) {
        }
    };

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> mp(n + 1);
        vector<int> vis(n + 1, 0);
        for (auto& edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        queue<Node> que;
        que.push(Node(1, 0, 1.0));
        while (!que.empty()) {
            Node node = que.front(); que.pop();
            vis[node.value] = 1;

            int count = 0;
            for (auto& c : mp[node.value]) {
                if(vis[c] == 1) continue;
                count++;
            }

            if(node.value == target) {
                if((count == 0 && t > node.time ) ||
                   node.time == t) return node.ratio;
            }

            for(auto& c : mp[node.value]) {
                if(vis[c] == 0) {
                    que.push(Node(c, node.time + 1, node.ratio * 1.0 / count));
                }
            }
        }
        return 0.0;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<vector<int>>  input = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};

    vector<vector<int>>  input = {};
    cout << s.frogPosition(1, input, 1, 1) << endl;
    return 0;
}
