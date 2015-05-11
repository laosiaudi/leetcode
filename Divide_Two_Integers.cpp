// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Divide_Two_Integers.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-08 17:26:55
// MODIFIED: 2015-05-08 17:31:44
#include <iostream>
using namespace std;

//reference:http://www.cnblogs.com/TenosDoIt/p/3795342.html
//reference:http://bangbingsyb.blogspot.hk/2014/11/divide-two-integers-divide-two-integers.html
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) return dividend>=0 ? INT_MAX : INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; //overflow problem
        
        bool isNeg = false;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) isNeg = true;
        unsigned long long dvd = abs((long long)dividend);
        unsigned long long dvs = abs((long long)divisor);
        unsigned long long dvs_original = dvs;
        
        int i = 0;
        while(dvs<<(i+1) <= dvd) i++;
        
        int res = 0;
        while(dvd>=dvs_original) {
            if(dvd >= dvs<<i) {
                dvd -= dvs<<i;
                res += 1<<i;
            }
            i--;
        }
        
        return isNeg ? 0-res : res;
    }
};