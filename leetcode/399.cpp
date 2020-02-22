#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution2 {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int M = equations.size();
        int N = 0; // 即将存储变量个数
        map<string, int> umap; // 标记变量是否出现过
        vector<double> res; // 结果
        for (int i = 0; i < M; i++) {
            // 需要将每个变量表示为数字序号，方便以后构建邻接矩阵
            string s0 = equations[i][0]; // 分子
            string s1 = equations[i][1]; // 分母
            if (umap.count(s0) == 0) { // 变量首次出现
                umap[s0] = N++; // 为该变量生成序号
            }
            if (umap.count(s1) == 0) {
                umap[s1] = N++;
            }
        }
        vector<vector<double>> adj(N, vector<double> (N, 0.0)); // N * N 邻接矩阵
        // 邻接矩阵初始化：
        for (int i = 0 ; i < M; i++) {
            // 对于"a"来说，如果存在"a/b"的表达式，则将adj[a, b]置为表达式的值，同时将adj[b, a]置为倒数
            // 需要找到string对应的序号
            string s0 = equations[i][0];
            string s1 = equations[i][1];
            int v = umap[s0];
            int w = umap[s1];
            adj[v][w] = values[i];
            adj[w][v] = double (1.0 / values[i]);
        }
        // 处理问题方程式：
        // 需要首先判断问题里的变量是否存在
        for (int i = 0; i < queries.size(); i++) {
            string s0 = queries[i][0];
            string s1 = queries[i][1];
            if (umap.count(s0) == 0 || umap.count(s1) == 0) {
                res.push_back(-1.0); // 如果变量不存在，则该表达式值为-1.0
                continue;
            }
            int v = umap[s0];
            int w = umap[s1];
            res.push_back(bfs(v, w, adj));
        }
        return res;
    }

    double bfs(int v, int w, vector<vector<double>>& adj) {
        if (adj.size() == 0) return -1.0;
        int N = adj[0].size();
        queue<pair<int, double>> q; // bfs 队列，用来记录遇到的结点和当前的乘法值
        map<int, int> umap; // 用来记录当前结点是否经过
        umap[v] = 1;
        if (adj[v][w] != 0.0) {
            return adj[v][w]; // 如果有已知的除法式的值，就直接返回
        }
        for (int i = 0; i < N; i++) {
            if (adj[v][i] != 0.0 && umap.count(i) == 0) { // 遇到一个没有经过且可以到达的结点
                q.push(make_pair(i, adj[v][i]));
                umap[i] = 1;
            }
        }
        while (!q.empty()) {
            int node = q.front().first;
            double last = q.front().second;
            q.pop();
            if (adj[node][w] != 0.0) {
                return last * adj[node][w];
            }
            for (int i = 0; i < N; i++) {
                if (adj[node][i] != 0.0 && umap.count(i) == 0) {
                    q.push(make_pair(i, last * adj[node][i]));
                    umap[i] = 1;
                }
            }
        }
        return -1.0;
    }
};


// accept
// dfs
// 4ms, 69.93%
// 10.2MB, 5.21%
class Solution1 {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        if(equations.size() == 0 || values.size() == 0 || equations.size() != values.size() ) return vector<double>();
        map<string, map<string, double>> graph;
        for(int i = 0; i < equations.size(); ++i) {
            vector<string>& equation = equations[i];
            string a = equation[0];
            string b = equation[1];
            if(graph.count(a) == 0) graph[a] = map<string, double>();
            graph[a].insert({b, values[i]});
            if(graph.count(b) == 0) graph[b] = map<string, double>();
            graph[b].insert({a, 1 / values[i]});
        }

        vector<double> res;
        for(int i = 0; i < queries.size(); ++i) {
            vector<string> query = queries[i];
            if(graph.count(query[0]) == 0 || graph.count(query[1]) == 0) {
                res.push_back(-1);
                continue;
            } else if(query[0] == query[1]) {
                res.push_back(1);
                continue;
            } else {
                set<string> visited;
                res.push_back(dfs(query[0], query[1], 1.0, visited, graph));
            }

        }
        return res;
    }

    double dfs(string a, string b, double result, set<string>& visited, map<string, map<string, double>>& _map) {
        if(_map[a].count(b) != 0) return _map[a][b] * result;

        for (auto& e : _map[a]) {
            if(visited.count(e.first) != 0) continue;
            visited.insert(e.first);
            double ret = dfs(e.first, b, result * e.second, visited, _map);
            if(ret != -1) return ret;
        }
        return -1;
    }

    double bfs(string a, string b, double result, set<string>& visited, map<string, map<string, double>>& _map) {

    }
};


int main(int argc, char *argv[])
{
	vector<vector<string> > equations;
	vector<double> values;
	vector<vector<string> > queries;
	vector<string>e1;
	e1.push_back("a");
	e1.push_back("e");
	vector<string>e2;
	e2.push_back("b");
	e2.push_back("e");
	vector<string>e3;
	e3.push_back("f");
	e3.push_back("g");
	equations.push_back(e1);
	equations.push_back(e2);
//	equations.push_back(e3);
	values.push_back(4.0);
	values.push_back(3.0);
//	values.push_back(5.0);
	vector<string>q1;
	vector<string>q2;
	vector<string>q3;
	vector<string>q4;
	vector<string>q5;
	q1.push_back("a");
	q1.push_back("b");
	q2.push_back("e");
	q2.push_back("e");
	q3.push_back("x");
	q3.push_back("x");
	q4.push_back("g");
	q4.push_back("f");
	q5.push_back("a");
	q5.push_back("x");
	vector<vector<string>>Q;
	Q.push_back(q1);
	Q.push_back(q2);
	Q.push_back(q3);
//	Q.push_back(q4);
//	Q.push_back(q5);
	Solution s;
	vector<double>res =  s.calcEquation(equations,values,Q);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}

    return 0;
}
