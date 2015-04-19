// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Spiral_Matrix.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-12 10:34:05
// MODIFIED: 2015-04-12 14:14:52

#include <iostream>
#include <vector>
using namespace std;
class BetterSolution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            vector<int>v;
            int line = matrix.size();
            if (line == 0)
                return v;
          if (line == 1)
                return matrix[0];
            int col = matrix[0].size();

            if (col == 1) {
                for (int i = 0; i < line; i ++)
                    v.push_back(matrix[i][0]);
                return v;
            }

            int top = 0;
            int left = 0;
            int right = col - 1;
            int bottom = line - 1;

            while (left < right && top < bottom) {
                for (int i = left; i < right; i ++)
                    v.push_back(matrix[top][i]);
                for (int i = top; i < bottom; i ++)
                    v.push_back(matrix[i][right]);
                for (int i = right; i > left; i --)
                    v.push_back(matrix[bottom][i]);
                for (int i = bottom; i > top; i --)
                    v.push_back(matrix[i][left]);
                top ++;
                right --;
                left ++;
                bottom --;
            }
            if (line % 2 != 0 || col % 2 != 0){
                if (left < right) {
                    for (int i = left; i <= right; i ++)
                        v.push_back(matrix[top][i]);
                } 
                if (top < bottom) {
                    for (int i = top; i <= bottom; i++)
                        v.push_back(matrix[i][left]);
                }
                if (left == right && top == bottom )
                    v.push_back(matrix[top][left]);
            }
            return v;
        }
};
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            vector<int>v;
            int line = matrix.size();
            if (line == 0)
                return v;
            int col = matrix[0].size();
            if (line == 1)
                return matrix[0];
            if (col == 1) {
                for (int i = 0; i < line; i ++)
                    v.push_back(matrix[i][0]);
                return v;
            }
            int total = line * col;
            int num = 0;
            for (int i = 1; i <= line - 1; i++) {
                for (int j = i - 1; j <= col - i && num <= total - 1; j ++) {
                    v.push_back(matrix[i - 1][j]);
                    num ++;
                }
                for (int j = i; j <= line - i && num <= total - 1; j ++) {
                    v.push_back(matrix[j][col - i]);
                    num ++;
                }
                for (int j = col - i - 1; j >=i - 1 && num <= total - 1; j --) {
                    v.push_back(matrix[line - i][j]);
                    num ++;
                }
                for (int j = line - i - 1; j >= i && num <= total - 1; j --) {
                    v.push_back(matrix[j][i - 1]);
                    num ++;
                }
            }
            return v;
        }
};

int main() {
    vector<vector<int> >v;
    vector<int>v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(8);
    vector<int>v2;
    v2.push_back(4);
    v2.push_back(0);
    v2.push_back(-1);
    v.push_back(v1);
    v.push_back(v2);
    Solution s;
    vector<int>re = s.spiralOrder(v);
    for (int i = 0;i < re.size(); i ++)
        cout << re[i] << " ";
    vector<vector<int> >vv;
    vector<int>v3;
    v3.push_back(1);
    v3.push_back(2);
    vv.push_back(v3);
    BetterSolution ss;
    vector<int>rr = ss.spiralOrder(vv);
    cout << endl;
    for (int i = 0;i < rr.size(); i ++)
        cout << rr[i] << " ";
    return 0;
}

