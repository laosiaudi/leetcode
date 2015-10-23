/*********************************************************************************
*     File Name           :     google_isstrobo.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-15 23:22]
*     Last Modified       :     [2015-10-15 23:32]
*     Description         :
**********************************************************************************/

#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution {
    public:
        bool isStrobogrammatic(string num) {
           int size = num.size();
           if (size == 0)
               return false;
           map<char, char>digit;
           digit['0'] = '0';
           digit['1'] = '1';
           digit['6'] = '9';
           digit['8'] = '8';
           digit['9'] = '6';

           string new_num;
           for (int i = num.size() - 1; i >= 0; i --) {
                       if (digit.find(num[i]) == digit.end())
                           return false;
                       new_num.push_back(digit[num[i]]);
           }
           return new_num.compare(num) == 0;
    }
};

int main() {
    Solution s;
    if (s.isStrobogrammatic("69"))
        printf("69\n");
    if (s.isStrobogrammatic("0"))
        printf("0\n");
    if (s.isStrobogrammatic("123"))
        printf("error\n");
    if (s.isStrobogrammatic("88"))
        printf("88\n");
    if (s.isStrobogrammatic("169"))
        printf("error\n");
    if (s.isStrobogrammatic("619"))
        printf("619\n");
    if (s.isStrobogrammatic("101"))
        printf("101\n");
    return 0;

}




