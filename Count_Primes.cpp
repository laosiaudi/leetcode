// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Count_Primes.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-06 14:45:31
// MODIFIED: 2015-05-06 14:58:49
#include <iostream>
using namespace std;

//reference:http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
class Solution {
    public:
        int countPrimes(int n) {
            vector<int>v(n + 1,1);
            int limit = sqrt(n);
            int counter = 0;
            for (int i = 2; i < n; i ++) {
                if (v[i] != 1)
                    continue;
                int temp = 2;
                for (; temp * i <= n; temp ++)
                    v[temp*i] = 2;
                counter ++;
            }
            return counter;
        }
};
