/*********************************************************************************
*     File Name           :     Longest_Consecutive_Sequence.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-28 22:20]
*     Last Modified       :     [2015-10-28 22:29]
*     Description         :
**********************************************************************************/
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if (nums.size() == 0)
                return 0;
            unordered_set<int>s;
            for (auto item : nums)
                s.insert(item);

            int maxLen = 1;
            while (!s.empty()) {
                auto item = *(std::begin(s));
                queue<int>q;
                int tmp = 1;
                q.push(item);
                while (!q.empty()) {
                    int target = q.front();
                    s.erase(target);
                    q.pop();
                    if (s.find(target + 1) != std::end(s)) {
                        tmp ++;
                        q.push(target + 1);
                    }
                    if (s.find(target - 1) != std::end(s)) {
                        tmp ++;
                        q.push(target - 1);
                    }
                }
                maxLen = max(maxLen, tmp);
            }
            return maxLen;
        }
};

