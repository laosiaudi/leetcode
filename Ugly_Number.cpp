/*********************************************************************************
*     File Name           :     Ugly_Number.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-06 21:06]
*     Last Modified       :     [2015-09-06 21:18]
*     Description         :
**********************************************************************************/

#include <iostream>

using namespace std;

class Solution {
    public:
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
};


