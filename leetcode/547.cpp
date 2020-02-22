#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution2 {
public:
    int peo[201];
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        for(int i=1;i<=n;i++){
            peo[i]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(M[i-1][j-1]==1){
                    peo[find(j)]=find(i);
                }

            }
        }

        int num=0;
        for(int i=1;i<=n;i++){
            if(find(i)==i){
                peo[i]=1;
                num++;
            }
            else peo[i]=0;
        }

        return num;
    }

    int find(int x){
        return peo[x]==x ? x : find(peo[x]);
    }
};

// 没有通过, 这个算法有个bug
// 当 M 遇到下面这种情况的时候， 判断(1,1) 坐标点的时候 还不能判断
//
// M:
// 1 0 0 1
// 0 1 1 0
// 0 1 1 1
// 1 0 1 1
// group:
// 1 0 0 1
// 0 2 2 0
// 0 2 2 2
// 1 0 2 2
// 2
class Solution3 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int LEN = M.size();
        vector<vector<int>> group(LEN, vector<int>());
        for (int i = 0; i < LEN; ++i) {
            group[i].resize(LEN);
        }

        for (int i = 0; i < LEN; ++i) {
            for(int j = 0; j < LEN; ++j) {
                group[i][j] = -1;
            }
        }

        int ret = 0;

        if (M[0][0] == 1) {
            group[0][0] = 1;
        }

        cout<<"M:"<<endl;
        printArray(M);

        ret = bfs(M, group, 0, 0, group[0][0]);

        cout<<"group:"<<endl;
        printArray(group);

        // for (int r = 0; r < LEN; ++r) {
        //     for (int c = 0; c < LEN; c++) {
        //         if (ret < group[r][c]) ret = group[r][c];
        //     }
        // }

        return ret;
    }

    void printArray (vector<vector<int>>& v) {
        for (auto& e : v) {
            for(auto& p : e) {
                cout<< p << " ";
            }
            cout<<endl;
        }
    }

    int bfs(vector<vector<int>>& M, vector<vector<int>>& group, int r, int c, int max) {


        if (r < 0 || r >= M.size() || c < 0 || c >= M.size()) {
            // boundary check
            return max;
        }

        if (M[r][c] == 1) {
            // left
            if (c - 1 >= 0) {
                if (group[r][c - 1] == -1) {
                    return max;
                }
                if (M[r][c - 1] == 1) {
                    group[r][c] = group[r][c - 1];
                }
            }

            //  top
            if (r - 1 >= 0) {
                if (group[r - 1][c] == -1) {
                    return max;
                }
                if (M[r - 1][c] == 1) {
                    group[r][c] = group[r - 1][c];
                }
            }

            // M[r][r] self
            if (r < c && group[r][r] != -1) {
                group[r][c] = group[r][r];
            }

            // M[c][c] self
            if (c < r && group[c][c] != -1) {
                group[r][c] = group[c][c];
            }

            if (group[r][c] == -1) {
                max++;
                group[r][c] = max;

            }
        } else {
            group[r][c] = 0;
        }

        // cout << "visit pos row: " << r << " col: " << c << " group: " << group[r][c] << " max: "<< max << endl;

        // go  right
        max = bfs(M, group, r, c + 1, max);
        // go down
        max = bfs(M, group, r + 1, c, max);

        return max;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;

        vector<bool> visited(M.size(), false);



        for (int i = 0; i < M.size(); ++i) {
            if (!visited[i]) {
                queue<int> que;
                que.push(i);
                while (!que.empty()) {
                    int cur = que.front();
                    que.pop();

                    visited[cur] = true;

                    for(int j = 0; j < M[cur].size(); ++j) {
                        if (!visited[j] && M[cur][j] == 1) {
                            que.push(j);
                        }
                    }
                }
                count++;
            }


        }

        return count;
    }

};

/**
 * accepted, time beats 81.60%
 * dfs
 */
class Solution4 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;

        const int LEN = M.size();
        vector<bool> visited(LEN, false);

        printArray(M);

        for (int i = 0; i < LEN; ++i) {
            if (!visited[i]) {
                dfs(M, visited, i);
                count++;
                cout << "already visit root i: " << i << " count: "<< count << endl;
            } else {
                cout << "skip visit root i: " << i << endl;
            }

        }

        return count;
    }

    void dfs(vector<vector<int>>& M, vector<bool>& visited, int dfsRootIndex) {
        cout<<"visit root success, rootIndex: " << dfsRootIndex << endl;
        visited[dfsRootIndex] = true;

        for (int i = 0; i < M[dfsRootIndex].size(); ++i) {

            if (!visited[i] && M[dfsRootIndex][i] == 1) {
                cout << "row: " << dfsRootIndex << " col: " << i << " valid" << endl;
                dfs(M, visited, i);
            } else {
                cout << "row: " << dfsRootIndex << " col: " << i << " invalid " << endl;
            }


        }
    }

    void printArray (vector<vector<int>>& v) {
        for (auto& e : v) {
            for(auto& p : e) {
                cout<< p << " ";
            }
            cout<<endl;
        }
    }
};


int main(int argc, char *argv[])
{

    vector<vector<int>> input2 = {{1,1,0},
                                 {1,1,0},
                                 {0,0,1}};

    vector<vector<int>> input3 = {{1,1,0},
                                 {1,1,1},
                                 {0,1,1}};

    vector<vector<int>> input = {{1,0,0,1},
                                 {0,1,1,0},
                                 {0,1,1,1},
                                 {1,0,1,1}};

    Solution s;

    cout << s.findCircleNum(input) << endl;
    return 0;
}
