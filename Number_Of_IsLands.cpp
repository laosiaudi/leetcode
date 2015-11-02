/*********************************************************************************
*     File Name           :     Number_Of_IsLands.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-02 00:03]
*     Last Modified       :     [2015-11-02 00:15]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        struct Node {
            int x;
            int y;
        };
        int numIslands(vector<vector<char>>& grid) {
            int num = 0;
            int row = grid.size();
            if (row == 0)
                return num;
            int col = grid[0].size();
            if (col == 0)
                return num;

            int x_mov[4] = {1,-1,0,0};
            int y_mov[4] = {0, 0, 1, -1};
            for (int i = 0; i < row; i ++) {
                for (int j = 0; j < col; j ++) {
                    if (grid[i][j] == '#' || grid[i][j] == '0')
                        continue;
                    Node start;
                    start.x = i;
                    start.y = j;
                    queue<Node>q;
                    q.push(start);
                    while (!q.empty()) {
                        Node tmp = q.front();
                        q.pop();
                        grid[tmp.x][tmp.y] = '#';
                        for (int k = 0; k < 4; k ++) {
                            int tmp_x = tmp.x + x_mov[k];
                            int tmp_y = tmp.y + y_mov[k];
                            if (tmp_x >= 0 && tmp_x < row &&
                                    tmp_y >= 0 && tmp_y < col
                                    && grid[tmp_x][tmp_y] == '1') {
                                Node new_node;
                                new_node.x = tmp_x;
                                new_node.y = tmp_y;
                                grid[new_node.x][new_node.y] = '#';
                                q.push(new_node);
                            }
                        }
                    }
                    num ++;
                }
            }
            return num;
        }
};


