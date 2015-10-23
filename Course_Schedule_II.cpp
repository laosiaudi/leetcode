/*********************************************************************************
*     File Name           :     Course_Schedule.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-22 22:05]
*     Last Modified       :     [2015-10-22 23:16]
*     Description         :
**********************************************************************************/
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<int>result;
            if (numCourses == 0)
                return result;
            unordered_map<int, int>pre_num;
            unordered_map<int, vector<int>>course;
            for (int i = 0; i < numCourses; i ++)
                pre_num[i] = 0;
            for (auto item : prerequisites) {
                pre_num[item.first] ++;
                course[item.second].push_back(item.first);
            }

            queue<int>q;
            int cnt = 0;
            for (int i = 0; i < numCourses; i ++) {
                if (pre_num[i] == 0) {
                    q.push(i);
                    cnt ++;
                }
            }

            while (!q.empty()) {
                int num = q.front();
                result.push_back(num);
                q.pop();
                for (auto item : course[num]) {
                    pre_num[item] --;
                    if (pre_num[item] == 0) {
                        q.push(item);
                        cnt ++;
                    }
                }
            }
            if (cnt != numCourses)
                result.clear();
            return result;
        }
};

int main() {
    Solution s;
    vector<pair<int, int>>v;
    v.push_back(std::make_pair(0,1));
    s.canFinish(2, v);
}


