// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Fraction_To_Recurring_Decimal.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-25 18:22:35
// MODIFIED: 2015-04-25 21:04:39
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if (numerator == 0)
                return "0";
            vector<int>v;
            bool isNega = false;
            if (numerator < 0 ^ denominator < 0) 
                isNega = true;
            long long int n = numerator, d = denominator;
            n = abs(n);
            d = abs(d);
            int temp = n/d;
            v.push_back(temp);
            long long int left = n % d;
            map<int, bool>m;
            bool isLoop = false;
            int loopDigit = -1;;
            while (left) {
                if (m.find(left) == m.end()){
                    m[left] = true;
                } else {
                   isLoop = true;
                   loopDigit = left * 10 / d;
                   break;
                }
                n = left * 10;
                left = n % d;
                temp = n / d;
                v.push_back(temp);
            }
            int size = v.size();
            if (size > 1)
                size ++;
            if (isLoop)
                size += 2;
            if (v[0] >= 10){
                vector<int>t;
                int real = v[0];
                while (real != 0) {
                    t.push_back(real % 10);
                    real = real / 10;
                }
                size = size - 1 + t.size();
                string digits(size, ' ');
                int index = 0;
                for (int i = t.size() - 1; i >= 0; i --)
                    digits[index ++] = t[i] - 0 + '0';
                if (v.size() == 1)
                    return digits;
                digits[index ++] = '.';
                for (int i = 1; i < v.size() - 1; i ++) {
                    if (v[i] == loopDigit)
                        digits[index ++] = '(';
                    digits[index ++] = v[i] - 0 + '0'; 
                }
                if (isLoop)
                    digits[index ++] = ')';
                if (isNega)
                    digits = "-" + digits;
                return digits;
            } else {
                string digits(size, ' ');
                digits[0] = v[0] - 0 + '0';
                if (v.size() == 1)
                    return digits;
                int index = 1;
                digits[index ++] = '.';
                for (int i = 1; i <= v.size() - 1; i ++) {
                    if (v[i] == loopDigit)
                        digits[index ++] = '(';
                    digits[index ++] = v[i] - 0 + '0'; 
                }
                if (isLoop)
                    digits[index ++] = ')';
                if (isNega)
                    digits = "-" + digits;
                return digits;
            }
        }
};


class BetterSolution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string result;
        if(numerator<0 ^ denominator<0 ) result+='-';   //异或，numerator<0和denominator<0仅有一个为真
        //转化为正数，INT_MIN转化为正数会溢出，故用long long。long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式。
        long long int n=numerator,d=denominator;
        n=abs(n);d=abs(d);              
        
        result+=to_string(n/d);  //整数部分
        long long int r=n%d;    //余数r
        if(r==0) return result;
        else result+='.';
        //下面处理小数部分，用哈希表
        map<int,int> m;
        while(r){
            //检查余数r是否在哈希表中，是的话则开始循环了
            if(m.find(r)!=m.end()){
                result.insert(m[r],1,'(');   //http://www.cplusplus.com/reference/string/basic_string/insert/
                result+=')';
                break;
            }
            m[r]=result.size();    //这个余数对应于result的哪个位置
            //正常运算
            r*=10;
            result+=to_string(r/d);
            r=r%d;
        }
        return result;
    }
};
int main () {
    Solution s;
    cout << s.fractionToDecimal(-1, -2147483648) << endl;
    cout << s.fractionToDecimal(2, 1) << endl;
    cout << s.fractionToDecimal(2, 3) << endl;
    cout << s.fractionToDecimal(19, 4) << endl;
    return 0;
}
