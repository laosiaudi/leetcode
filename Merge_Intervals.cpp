/*********************************************************************************
*     File Name           :     Merge_Intervals.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-18 00:55]
*     Last Modified       :     [2015-10-18 01:05]
*     Description         :
**********************************************************************************/

/**
 *  * Definition for an interval.
 *   * struct Interval {
 *    *     int start;
 *     *     int end;
 *      *     Interval() : start(0), end(0) {}
 *       *     Interval(int s, int e) : start(s), end(e) {}
 *        * };
 *         */
class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval>result;
            if (intervals.size() == 0)
                return result;
            std::sort(std::begin(intervals), std::end(intervals),  [](const Interval & first, const Interval & second){
                                return first.start < second.start;
                                        });
            Interval compare = intervals[0];
            for (int i = 1; i < intervals.size(); i ++) {
                Interval tmp = intervals[i];
                if (compare.end < tmp.start) {
                    result.push_back(compare);
                    compare = tmp;
                } else if (compare.start > tmp.end) {
                    result.push_back(tmp);
                } else {
                    compare.start = compare.start < tmp.start ? compare.start : tmp.start;
                    compare.end = compare.end > tmp.end ? compare.end : tmp.end;
                }
            }
            result.push_back(compare);
            return result;
        }
};


