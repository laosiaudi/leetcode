// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Palindrome_Number.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-06 11:38:20
// MODIFIED: 2015-05-06 11:51:05
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0)
                return false;//negative numbers are not palindrome_number
            int y = reverse(x);
            if (y == x)
                return true;
            else
                return false;
        }            
        int reverse(int x) {
            long long res = 0;//handle overflow
           
            while (x != 0) {
                int temp = x % 10;
                res = res* 10 + temp;
                x = x / 10;
            }
            if (res > INT_MAX || res < INT_MIN) //handle overflow
                return 0;
            return res;
            
        }

};

//simple solution
class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0)
                return false;
            int div = 1;
            while (x/div >= 10) {
                div *= 10;
            }

            while (x > 0) {
                int first = x/div;
                int last = x % 10;
                if (first != last)
                    return false;
                x = x % div / 10;
                div /= 100;
            }
            return true;
        }
};

int main() {
    Solution s;
    bool k = s.isPalindrome(-2147447412);
    if (k)
        cout << "yes\n";
    return 0;
}
