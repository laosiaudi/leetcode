/*********************************************************************************
*     File Name           :     Insert_Interval.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-18 00:02]
*     Last Modified       :     [2015-10-18 00:52]
*     Description         :
**********************************************************************************/
#include <vector>
#include <iostream>

using namespace std;
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
//TLE erase cost too much time
class Solution {
    public:
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            vector<Interval>::iterator it = intervals.begin();
            while (it != intervals.end()) {
                if (it->end < newInterval.start) {
                    it ++;
                    continue;
                } else if (it->start > newInterval.end) {
                    intervals.insert(it, newInterval);
                    return intervals;
                } else {
                    newInterval.start = newInterval.start < it->start ? newInterval.start : it->start;
                    newInterval.end = newInterval.end > it->end ? newInterval.end : it->end;
                    it = intervals.erase(it);
                }
            }
            intervals.push_back(newInterval);
            return intervals;
        }
};

class Solution {
    public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            vector<Interval> res;
            int index = 0;
            while(index < intervals.size() && intervals[index].end < newInterval.start){
                        res.push_back(intervals[index++]);
            }
            while(index < intervals.size() && intervals[index].start <= newInterval.end){
                        newInterval.start = min(newInterval.start, intervals[index].start);
                        newInterval.end = max(newInterval.end, intervals[index].end);
                        index++;
            }
            res.push_back(newInterval);
            while(index < intervals.size()){
                res.push_back(intervals[index++]);
            }
            return res;
        }
};

int main() {
    Interval i1(1,2);
    Interval i2(3,4);
    Interval i3(5,6);
    Interval i4(7,8);
    Interval i5(9,10);
    vector<Interval>v;
    v.push_back(i1);
    v.push_back(i2);
    v.push_back(i3);
    v.push_back(i4);
    v.push_back(i5);
    Interval ii(0,11);
    Solution s;
    v = s.insert(v, ii);
    for (auto item : v) {
        cout << item.start << " " << item.end << endl;
    }
    return 0;
}


