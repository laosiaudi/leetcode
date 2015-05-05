// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Sqrt_x.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-05 12:31:43
// MODIFIED: 2015-05-05 15:55:19
#include <iostream>
using namespace std;

//TLE
class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0)
                return x;
            if (x < 0)
                return -1;

            for (int i = 1;i <= x/2; i ++) {
                if (i * i > x)
                    return i - 1;
            }
        }
};

//binary search
class Solution {
    public:
        int mySqrt(int x) {
            long long i = 0; //use long long
            long long j = x/2 + 1;

            while (i <= j) {
                long long mid = (i + j)/2;
                long long sq = mid * mid;
                if (sq == x)
                    return mid;
                else if (sq < x)
                    i = mid + 1;
                else
                    j = mid - 1;
            }
            return j;
        }
};

//Newton 
//reference: http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0) return 0;
            double last = 0;
            double res = 1;
            while (res != last) {
                last = res;
                res = (res + x / res) / 2;
            }
            return int(res);
        }
};

