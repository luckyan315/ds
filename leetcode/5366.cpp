#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// accept
// 124ms, beats 100.00%
// 27MB, 100.00%
class Solution1 {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return false;
        int dir = grid[0][0];
        if(dir == 1) {
            if(dfs(0, 0, grid, 1)) return true;
            if(dfs(0, 0, grid, 3)) return true;
        } else if (dir == 2) {
            if(dfs(0, 0, grid, 0)) return true;
            if(dfs(0, 0, grid, 2)) return true;
        } else if (dir == 3) {
            if(dfs(0, 0, grid, 3)) return true;
            if(dfs(0, 0, grid, 2)) return true;
        } else if (dir == 4) {
            if(dfs(0, 0, grid, 1)) return true;
            if(dfs(0, 0, grid, 2)) return true;
        } else if (dir == 5) {
            if(dfs(0, 0, grid, 0)) return true;
            if(dfs(0, 0, grid, 3)) return true;
        } else {
            if(dfs(0, 0, grid, 0)) return true;
            if(dfs(0, 0, grid, 1)) return true;
        }
        return false;
    }

    // prevDir: 0 up, 1 right, 2, down, 3 left
    bool dfs(int x, int y, vector<vector<int>>& grid, int prevDir) {
        bool rightDir = true;
        int nRow = grid.size();
        int nCol = grid[0].size();
        int dir = grid[x][y];
        switch (dir) {
        case 1:
            if(prevDir == 1) {
                // right 2 left
                if(y - 1 >= 0 && dfs(x, y - 1, grid, 1)) {
                    return true;
                }
            } else if(prevDir == 3) {
                // left2right
                if(y + 1 < nCol && dfs(x, y + 1, grid, 3)) {
                    return true;
                }
            } else {
                rightDir = false;
            }
            break;
        case 2:
            if(prevDir == 0) {
                // up to down
                if(x + 1 < nRow && dfs(x + 1, y, grid, 0)) {
                    return true;
                }
            } else if (prevDir == 2) {
                // down to up
                if(x - 1 >= 0 && dfs(x - 1, y, grid, 2)) {
                    return true;
                }
            } else {
                rightDir = false;
            }

            break;
        case 3:
            // left to down
            if(prevDir == 3 ) {
                if(x + 1 < nRow && dfs(x + 1, y, grid, 0)) {
                    return true;
                }
            } else if(prevDir == 2) {
                if(y - 1 >= 0 && dfs(x, y - 1, grid, 1)) {
                    return true;
                }
            } else {
                rightDir = false;
            }
            break;
        case 4:
            // right to down
            if(prevDir == 1) {
                if(x + 1 < nRow && dfs(x + 1, y, grid, 0)) {
                    return true;
                }
            } else if(prevDir == 2)  {
                if(y + 1 < nCol && dfs(x, y + 1, grid, 3)) {
                    return true;
                }
            } else {
                rightDir = false;
            }
            break;
        case 5:
            // left to up
            if(prevDir == 3) {
                if(x - 1 >= 0 && dfs(x - 1, y, grid, 2)) {
                    return true;
                }
            } else if(prevDir == 0) {
                if(y - 1 >= 0 && dfs(x, y - 1, grid, 1)) {
                    return true;
                }
            } else {
                rightDir = false;
            }
            break;
        case 6:
            // right to up
            if(prevDir == 0) {
                if(y + 1 < nCol && dfs(x, y + 1, grid, 3)) {
                    return true;
                }
            } else if (prevDir == 1) {
                if(x - 1 >= 0 && dfs(x - 1, y, grid, 2)) {
                    return true;
                }
            } else {
                rightDir = false;
            }
            break;
        }

        if(rightDir && x == grid.size() - 1 && y == grid[0].size() - 1) {
            return true;
        }

        return false;
    }

};

// https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/solution/5366-jian-cha-wang-ge-zhong-shi-fou-cun-zai-you-xi/

class Solution_copy_from_leetcode {
public:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//定义四个方向，上下左右
    //建立形状和方向的映射
    int a[7][2] = {{0,0},{2,3},{0,1},{1,2},{1,3},{0,2},{0,3}};
    int n,m;
    bool visited[500][500];
    //判读顶点是否规范
    bool check(int x,int y){
        if(x < 0 || x >= m || y<0 || y >= n){
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<int>>& grid){
        if(check(x,y)==false) return;
        visited[x][y] = true;//标记访问
        // cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
        int tmpdir = grid[x][y];//取出该点的街道类型
        for(int i=0;i<2;i++){
            int t = a[tmpdir][i];
            int tx = dir[t][0] + x;
            int ty = dir[t][1] + y;
            //(tx,ty)是下一跳可到达的点。需要再去判读，该点是否和
            if(check(tx,ty)){
                // cout<<"tx="<<tx<<"\t"<<"ty="<<ty<<endl;
                int tmp = grid[tx][ty];//得到下一步的街道类型
                for(int k=0;k<2;k++){
                    int p = a[tmp][k];//得到该街道的两个方向
                    if(dir[t][0] + dir[p][0]==0 && dir[t][1]+dir[p][1]==0){//判读是否可以走通
                        if(!visited[tx][ty]){
                            dfs(tx,ty,grid);
                        }
                    }
                }
            }
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();//行数
        n = grid[0].size();//列数
        dfs(0,0,grid);
        if(visited[m-1][n-1] == true){
            return true;//可到达
        }
        return false;
    }
};

class Solution_leetcode {
    int map[1000][1000];
    void fill(int i, int j, int s)
    {
        map[i+1][j+1]=1;
        if(s==1) map[i+1][j]=map[i+1][j+2]=1;
        if(s==2) map[i][j+1]=map[i+2][j+1]=1;
        if(s==3) map[i+1][j]=map[i+2][j+1]=1;
        if(s==4) map[i+1][j+2]=map[i+2][j+1]=1;
        if(s==5) map[i+1][j]=map[i][j+1]=1;
        if(s==6) map[i+1][j+2]=map[i][j+1]=1;
    }
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    void dfs(int x, int y)
    {
        map[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(map[xx][yy]==0)continue;
            dfs(xx, yy);
        }
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(map,0,sizeof map);
        int n = grid.size();
        int m = grid[0].size();
        for(int i=1;i<=3*n;i+=3)
            for(int j=1;j<=3*m;j+=3)
                fill(i,j,grid[i/3][j/3]);
        dfs(2,2);
        return map[3*n-1][3*m-1]==0;
    }
};

// https://www.youtube.com/watch?v=SpMez87v0O8
class Solution_from_youtube_bitmap_mask {
public:
    int m, n;
    vector<vector<int> > g;
    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1}, t[6] = {4|8, 1|2, 8|1, 4|1, 8|2, 4|2};
    vector<vector<bool> > vis;

    bool dfs(int i, int j) {
        if (i == m - 1 && j == n - 1) return true;
        vis[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            if (t[g[i][j]-1]>>k&1^1) continue;
            int ni = i + di[k], nj = j + dj[k];
            if (ni<0 || ni>=m || nj<0 || nj>=n || vis[ni][nj]) continue;
            int k2 = k^1;
            if (t[g[ni][nj]-1]>>k2&1^1) continue;
            if (dfs(ni, nj)) return true;
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g = grid;
        vis = vector<vector<bool> >(m, vector<bool>(n, 0));
        return dfs(0,0);
    }
};

// accept
// 172ms, 100.00%
// 82MB, 100.00%
class Solution {
public:
    int r, c;

    // direction row
    vector<int> dr = {1, -1, 0, 0};
    // direction column
    vector<int> dc = {0, 0, 1, -1};
    // direction mask
    // down: 1,  0x0001
    // up: 2,    0x0010
    // right: 4, 0x0100
    // left: 8,  0x1000
    vector<int> dm = {4|8, 1|2, 1|8, 1|4, 8|2, 2|4};

    bool dfs(int x, int y, vector<vector<int>>& grid,
        vector<vector<bool>>& vis) {
        if(x == r -1 && y == c -1 ) return true;
        vis[x][y] = true;

        // down, up, right, left
        for (int k = 0; k < 4; ++k) {
            if((dm[grid[x][y] - 1] >> k & 1) ^ 1) continue;
            int xr = x + dr[k];
            int yc = y + dc[k];
            if(xr < 0 || xr >= r || yc < 0 || yc >= c || vis[xr][yc]) continue;

            int rk = k ^ 1;
            if((dm[grid[xr][yc] - 1] >> rk & 1) ^ 1) continue;
            if(dfs(xr, yc, grid, vis)) return true;
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        vector<vector<bool>> vis(r, vector<bool>(c, false));
        return dfs(0, 0, grid, vis);
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int>> input = {{1, 1, 2}};
    // vector<vector<int>> input = {{2, 4, 3}, {6, 5, 2}};
    cout << s.hasValidPath(input) << endl;
    return 0;
}
