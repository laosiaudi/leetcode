// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Unique_Paths.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-11 19:01:27
// MODIFIED: 2015-04-11 20:08:01
// If use method like DFS, will TLE. Should store state first
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 class Solution {
     public:
     struct grid {
        int x;
        int y;
     };
     int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
         int m = obstacleGrid.size();
         int n = obstacleGrid[0].size();
         if (m == 1 && n == 1)
             return obstacleGrid[0][0] == 1 ? 0 : 1;
         if (obstacleGrid[0][0] == 1)
             return 0;
         for (int i = 0;i < m;i ++) {
            for (int j = 0; j < n;j ++) {
                visit[i][j] = false;
                way[i][j] = 0;
            }
         }
         return recursivePath(1, 0, m, n, obstacleGrid) + recursivePath(0, 1, m, n, obstacleGrid);
     }
     int recursivePath(int x, int y, int line, int col, vector<vector<int> > &obstacleGrid) {
         if (x < 0 || x >= line || y < 0 || y >= col || obstacleGrid[x][y] == 1)
             return 0;
         if (x == line - 1 && y == col - 1)
             return 1;
         if (visit[x][y] == true)
             return way[x][y];
         else {
             visit[x][y] = true;
             way[x][y] = recursivePath(x, y + 1, line, col, obstacleGrid) + recursivePath(x + 1, y , line , col, obstacleGrid);
             return way[x][y];
         }
     }
     bool visit[100][100];
     int way[100][100];
 };

int main() {
    Solution s;
    cout <<  s.uniquePathsWithObstacles(23,12) << endl;
    cout <<  s.uniquePathsWithObstacles(3,3) << endl;
    cout <<  s.uniquePathsWithObstacles(2,2) << endl;
    return 0;
}
