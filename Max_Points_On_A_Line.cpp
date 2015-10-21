/*********************************************************************************
*     File Name           :     Max_Points_On_A_Line.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-19 15:51]
*     Last Modified       :     [2015-10-19 16:06]
*     Description         :
**********************************************************************************/

/**
 *  * Definition for a point.
 *   * struct Point {
 *    *     int x;
 *     *     int y;
 *      *     Point() : x(0), y(0) {}
 *       *     Point(int a, int b) : x(a), y(b) {}
 *        * };
 *         */
class Solution {
    public:
        int maxPoints(vector<Point>& points) {
            unordered_map<float, int> slope;
            int maxNum = 0;
            for (int i = 0;i < points.size(); i ++) {
                slope.clear();
                slope[INT_MIN] = 0;
                int duplicate = 1;
                for (int j = i + 1; j < points.size(); j ++) {
                    if (points[j].x == points[i].x && points[j].y == points[i].y) {
                        duplicate ++;
                        continue;
                    }

                    float k = (points[j].x == points[i].x) ? INT_MAX :  (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    if (slope.find(k) == std::end(slope))
                        slope[k] = 1 ;
                    else
                        slope[k] ++;
                }

                for (auto it : slope) {
                    if (it.second + duplicate > maxNum)
                        maxNum = it.second + duplicate;
                }
            }

            return maxNum;
        }
};


