/*********************************************************************************
*     File Name           :     Ugly_Number_II.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-07 10:55]
*     Last Modified       :     [2015-09-07 11:26]
*     Description         :
**********************************************************************************/

#include <iostream>

using namespace std;

class Solution {
    public:
        //normal solution -- TLE
        int nthUglyNumber(int n) {
            int cnt = 1;
            int start = 1;
            for (; cnt != n; start ++) {
                if (isUgly(start))
                    cnt ++;
            }
            return start - 1;

        }
        bool isUgly(int num) {
            if (num <= 0)
                return false;

            if (num == 1)
                return true;

            int div[3] = {2, 3, 5};
            int base = 0;
            int tmp = num;
            while (base <= 2) {
                if (tmp % div[base] == 0)
                    tmp = tmp / div[base];
                else
                    base ++;
                if (tmp == 1)
                    return true;
            }
            return false;
        }
        //better solution
        //reference:http://www.cnblogs.com/grandyang/p/4743837.html
        int nthUglyNumber(int n) {
            vector<int>res(1, 1);
            int i2 = 0, i3 = 0, i5 = 0;
            while (res.size() < n) {
                int m2 = res[i2] * 2;
                int m3 = res[i3] * 3;
                int m5 = res[i5] * 5;
                int tmp = m2 < m3 ? m2 : m3;
                int mm = tmp < m5 ? tmp : m5;
                if (mm == m2)
                    i2 ++;
                if (mm == m3)
                    i3 ++;
                if (mm == m5)
                    i5 ++;
                res.push_back(mm);
            }
            return res[n - 1];
        }
};


