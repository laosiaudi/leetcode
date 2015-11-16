/*********************************************************************************
*     File Name           :     Sliding_Window_Maximum.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-15 17:38]
*     Last Modified       :     [2015-11-15 19:56]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        vector<int> simple_maxSlidingWindow(vector<int>& nums, int k) {
            vector<int>result;
            deque<int>q;

            for (int i = 0; i < nums.size(); i ++) {
                if (!q.empty() && q.front() == i - k)
                    q.pop_front();

                while (!q.empty() && nums[q.back()] < nums[i])
                    q.pop_back();

                q.push_back(i);

                if (i >=  k - 1)
                    result.push_back(nums[q.front()]);
            }
            return result;
        }
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int>result;

            if (k == 0 || nums.size() == 0)
                return result;

            priority_queue<int>q;
            map<int, int>m;
            for (int i = 0; i < k; i ++) {
                q.push(nums[i]);
                if (m.find(nums[i]) == m.end())
                    m[nums[i]] = 1;
                else
                    m[nums[i]] ++;
            }
            result.push_back(q.top());

            for (int i = k; i < nums.size(); i ++) {
                int top = q.top();
                m[nums[i - k]] --;

                while (m[top] == 0) {
                    q.pop();
                    if (q.empty())
                        break;
                    top = q.top();
                }
                q.push(nums[i]);
                if (m.find(nums[i]) == m.end())
                    m[nums[i]] = 1;
                else
                    m[nums[i]] ++;
                result.push_back(q.top());
            }
            return result;
        }
};
