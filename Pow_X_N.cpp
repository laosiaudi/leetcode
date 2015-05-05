// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Pow_X_N.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-05 18:07:36
// MODIFIED: 2015-05-05 18:26:58
#include <iostream>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            if (n==0) return 1;
            double t = myPow(x,n/2);
            if (n%2) {
                return n<0 ? 1/x*t*t : x*t*t;
            } else {
                return t*t;
            }
        }

        
};
