// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Multiply_Strings.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-06 12:59:32
// MODIFIED: 2015-05-06 13:27:40
#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            int len1 = num1.size();
            int len2 = num2.size();
            if (len1 == 0 || len2 == 0)
                return "";

            int numOfZeros = 0;
            string res = "0";
            for (int i = len2 - 1;i >= 0; i --) {
                string temp = doMultiply(num1, num2[i], numOfZeros);
                res = doAdd(temp, res);
                numOfZeros ++;
            }
            if (res[0] == '0')
                return "0";
            return res;
        }

        string doMultiply(string num1, char num, int numOfZeros) {
            int len = num1.size();
            string res(len, ' ');
            int carry = 0;
            for (int i = len - 1; i >= 0; i--) {
                int temp = (num1[i] - '0')*(num - '0') + carry;
                carry = temp / 10;
                res[i] = temp % 10 + '0';
            }
            if (carry > 0) {
                string s(1, carry + '0');
                res = s + res;
            }

            for (int i = 1; i <= numOfZeros; i ++) {
                res = res + "0";
            }
            return res;
        }

        string doAdd(string s1, string s2) {
            if (s2 == "0")
                return s1;
            if (s1 == "0")
                return s2;

            int len1 = s1.size();
            int len2 = s2.size();

            if (len1 < len2) {
                for (int i = 1;i <= len2 - len1; i ++) {
                    s1 = "0" + s1;
                }
            }
            if (len2 < len1) {
                for (int i = 1; i <= len1 - len2; i ++)
                    s2 = "0" + s2;
            }

            int maxLen = len1 > len2? len1 : len2;
            string res(maxLen, ' ');
            int carry = 0;
            for (int i = maxLen - 1; i >= 0; i --) {
               int temp = s1[i] - '0' + s2[i] - '0' + carry;
               carry = temp / 10;
               temp = temp % 10;
               res[i] = temp + '0';
            }
            if (carry > 0) {
                string s(1, carry + '0');
                res = s + res;
            }
            return res;
        }


};

int main() {
    Solution s;
    cout << s.multiply("0", "0");
}
