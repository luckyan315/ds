#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

class Solution2
{
public:
    //右 -> 右下 -> 下 -> 左下 -> 左 -> 左上 -> 上 -> 右上
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int stat[50][50];                               //状态
    typedef pair<int, int> Point;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        int rsize = board.size(), csize = board[0].size();
        queue<Point> que;

        //点击到地雷
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        //初始化状态
        memset(stat, 0, sizeof(stat));
        que.push({click[0], click[1]});
        stat[click[0]][click[1]] = 1;

        while(!que.empty())
        {
            Point p = que.front(); que.pop();

            //计算相邻的地雷的数量
            int cnt = 0, r = p.first, c = p.second;
            for(int i = 0; i != 8; ++i)
            {
                int nnr = r + dr[i], nnc = c + dc[i];
                //没有越界, 并且为地雷的情况。
                if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize
                   && (board[nnr][nnc] == 'M' || board[nnr][nnc] == 'X'))
                    ++cnt;
            }

            // 如果有地雷, 直接揭露。
            if(cnt > 0)
                board[r][c] = cnt + '0';

            // 否则揭露为B, 并增广其相邻的元素
            else
            {
                board[r][c] = 'B';
                for(int i = 0; i != 8; ++i)
                {
                    int nnr = r + dr[i], nnc = c + dc[i];
                    //相邻的顶点没有越界, 并且没有被增加到增广队列当中, 且没有被翻过为E
                    if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize  && stat[nnr][nnc] == 0 && board[nnr][nnc] == 'E')
                    {
                        que.push({nnr, nnc});
                        stat[nnr][nnc] = 1;
                    }
                }
            }
        }
        return board;
    }
};

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (click.empty() || board.empty()) return vector<vector<char>>();

        vector<vector<char>>& ans = board;
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), -1));

        int clickX = click[0];
        int clickY = click[1];

        if (board[clickX][clickY] == 'M') {
            ans[clickX][clickY] = 'X';
            return ans;
        }

        queue<vector<int>> cache;

        bfs(board, clickX, clickY, cache, ans, visited);

        return ans;
    }

    void bfs(vector<vector<char>>& board,
             int clickx, int clicky,
             queue<vector<int>>& cache,
             vector<vector<char>>& ans, vector<vector<int>>& visited) {

        cache.push({clickx, clicky});
        visited[clickx][clicky] = 1;

        while (!cache.empty()) {
            vector<int> cur = cache.front();
            int x = cur[0];
            int y = cur[1];

            cache.pop();

            int cntBoom = getBoomCount(board, x, y);
            if (cntBoom > 0) {
                ans[x][y] = '0' + cntBoom;
            } else {
                ans[x][y] = 'B';

                // down
                enqueue(board, cache, x + 1, y, ans, visited);
                // up
                enqueue(board, cache, x - 1, y, ans, visited);
                // right
                enqueue(board, cache, x, y + 1, ans, visited);
                // left
                enqueue(board, cache, x, y - 1, ans, visited);

                // top-right
                enqueue(board, cache, x - 1, y + 1, ans, visited);
                // top-left
                enqueue(board, cache, x - 1, y - 1, ans, visited);
                // down-right
                enqueue(board, cache, x + 1, y + 1, ans, visited);
                // down-left
                enqueue(board, cache, x + 1, y - 1, ans, visited);
            }

        }
    }

    void enqueue(vector<vector<char>>& board, queue<vector<int>>& cache, int x, int y, vector<vector<char>>& ans, vector<vector<int>>& visited) {
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && visited[x][y] == -1 && board[x][y] == 'E') {
            cache.push({x, y});
            visited[x][y] = 1;
        }
    }

    int getBoomCount(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        if (x - 1 >= 0 && board[x - 1][y] == 'M') cnt++;
        if (x + 1 < board.size() && board[x + 1][y] == 'M') cnt++;
        if (y - 1 >= 0 && board[x][y - 1] == 'M') cnt++;
        if (y + 1 < board[0].size() && board[x][y + 1] == 'M') cnt++;
        if (x - 1 >= 0 && y - 1 >=0 &&  board[x - 1][y - 1] == 'M') cnt++;
        if (x - 1 >= 0 && y + 1 < board[0].size() && board[x - 1][y + 1] == 'M') cnt++;
        if (x + 1 < board.size() && y - 1 >= 0 && board[x + 1][y - 1] == 'M') cnt++;
        if (x + 1 < board.size() && y + 1 < board[0].size() && board[x + 1][y + 1] == 'M') cnt++;
        return cnt;
    }
};

int main(int argc, char *argv[])
{

    vector<vector<char>> input3 = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};

    vector<vector<char>> input = {{'E','E','E','E','E','E','E','E'},
                                  {'E','E','E','E','E','E','E','M'},
                                  {'E','E','M','E','E','E','E','E'},
                                  {'M','E','E','E','E','E','E','E'},
                                  {'E','E','E','E','E','E','E','E'},
                                  {'E','E','E','E','E','E','E','E'},
                                  {'E','E','E','E','E','E','E','E'},
                                  {'E','E','M','M','E','E','E','E'}};

    // vector<vector<char>> input = {{'E','E','E','E','E','E','E','E'},
    //                               {'E','E','E','E','E','E','E','M'},
    //                               {'E','E','M','E','E','E','E','E'},
    //                               {'M','E','E','E','E','E','E','E'},
    //                               {'E','E','E','E','E','E','E','E'},
    //                               {'E','E','E','E','E','E','E','E'},
    //                               {'E','E','E','E','E','E','E','E'},
    //                               {'E','E','M','M','E','E','E','E'}};

    // vector<vector<char>> output = {{'B','B','B','B','B','B','1','E'},
    //                                {'B','1','1','1','B','B','1','M'},
    //                                {'1','E','M','1','B','B','1','1'},
    //                                {'M','E','1','1','B','B','B','B'},
    //                                {'1','1','B','B','B','B','B','B'},
    //                                {'B','B','B','B','B','B','B','B'},
    //                                {'B','1','2','2','1','B','B','B'},
    //                                {'B','1','M','M','1','B','B','B'}};

    // vector<vector<char>> my_output = {{'B','B','B','B','B','B','1','E'},
    //                                   {'B','1','1','1','B','B','1','M'},
    //                                   {'1','2','M','1','B','B','1','1'},
    //                                   {'M','2','1','1','B','B','B','B'},
    //                                   {'1','1','B','B','B','B','B','B'},
    //                                   {'B','B','B','B','B','B','B','B'},
    //                                   {'B','1','2','2','1','B','B','B'},
    //                                   {'B','1','M','M','1','B','B','B'}};


    vector<vector<char>> input2(
        {{'B', '1', 'E', '1', 'B'},
            {'B', '1', 'M', '1', 'B'},
           {'B', '1', '1', '1', 'B'},
            {'B', 'B', 'B', 'B', 'B'}});

    vector<int> click({0, 0});

    // vector<vector<char>> input(
    //     {{'E', 'E'},
    //         {'E', 'M'}});

    // vector<int> click({0, 0});


    vector<vector<char>> ans;

    Solution s;
    ans = s.updateBoard(input, click);

    for (auto& r : ans) {
        for (auto& c : r) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
