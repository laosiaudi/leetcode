/*********************************************************************************
*     File Name           :     Candy.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-25 17:41]
*     Last Modified       :     [2015-10-25 19:23]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        int candy(vector<int>& ratings) {
            int size = ratings.size();
            vector<int>v(size, 1);
            v[0] = 1;
            for (int i = 1; i < size; i ++) {
                if (ratings[i] > ratings[i - 1])
                    v[i] = v[i - 1] + 1;
                else
                    v[i] = 1;
            }

            int sum = v[size - 1];
            for (int i = size - 2; i >= 0;i --) {
                int tmp = 1;
                if (ratings[i] > ratings[i + 1]) {
                    tmp = v[i + 1] + 1;
                }

                sum += (tmp > v[i] ? tmp : v[i]);
                v[i] = tmp;
            }
            return sum;
        }
};
