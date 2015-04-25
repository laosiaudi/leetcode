// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Repeated_DNA_Sequences.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-25 10:23:32
// MODIFIED: 2015-04-25 17:48:06
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
//MLE version, need to encode the string
class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            vector<string>v;
            map<string , bool>m;
            if (s.size() < 10)
                return v;
            for (int i = 0; i < s.size() - 10; i ++) {
               string temp = s.substr(i, 10);
               if (m.find(temp) == m.end())
                   m[temp] = false;
               else {
                   if (m[temp] != true) {
                       m[temp] = true;
                       v.push_back(temp);
                   }
               }
            }
            return v;
        }

};

//442ms
class BetterSolution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            vector<string>v;
            map<int , bool>m;
            if (s.size() < 10)
                return v;
            for (int i = 0; i < s.size() - 9; i ++) {
               string temp = s.substr(i, 10);
               int num = string2Long(temp);
               if (m.find(num) == m.end())
                   m[num] = false;
               else {
                   if (m[num] != true) {
                       m[num] = true;
                       v.push_back(long2String(num));
                   }
               }
            }
            return v;
        }

        long string2Long(string s) {
            long num = 0;
            char trans[20];
            int index  = 0;
            for (int i = 0; i < 10; i ++) {
                if (s[i] == 'A') {
                    trans[index ++] = '0';
                    trans[index ++] = '0';
                } else if (s[i] == 'C') {
                    trans[index ++] = '0';
                    trans[index ++] = '1';
                } else if (s[i] == 'G') {
                    trans[index ++] = '1';
                    trans[index ++] = '0';
                } else {
                    trans[index ++] = '1';
                    trans[index ++] = '1';
                }
            }
            index = 0;
            for (int i = 19; i >= 0; i --) {
                if (trans[i] == '1')
                    num += 1 * pow(2, index++);
                else
                    index ++;
            }
            return num;
        }

        string long2String(long num) {
            string s(10, ' ');
            int single = 3;
            int index = 0;
            for (int i = 18; i >= 0; i -= 2) {
                int temp = num & (single << i);
                temp = temp >> i;
                if (temp == 0)
                    s[index ++] = 'A';
                else if (temp == 1)
                    s[index ++] = 'C';
                else if (temp == 2)
                    s[index ++] = 'G';
                else
                    s[index ++] = 'T';
            }
            return s;
        }

};

//258ms
class BestSolution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            vector<string> ans;
            int result = 0;
            if (s.size() < 10)
                return ans;
            map<char, int>m;
            m['A'] = 0;
            m['C'] = 1;
            m['G'] = 2;
            m['T'] = 3;

            map<int, bool>check;
            for (int i = 0; i < 10; i ++)
                result = (result << 2) + m[s[i]];
            check[result] = false;
            for (int i = 10; i < s.size(); i ++) {
                result = ((result & 0x3ffff)<< 2) + m[s[i]]; //不加&0x3ffff就会一直忘左移而不会将最高位丢掉，知道左移到硬件上能到的最高的位数
                if (check.find(result) == check.end())
                    check[result] = false;
                else {
                    if (check[result] != true) {
                        check[result] = true;
                        ans.push_back(string(s, i - 9, 10));
                    }
                }
            }
            return ans;
        }
};
int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string t = "AAAAAAAAAAA";
    BestSolution ss;
    vector<string> v = ss.findRepeatedDnaSequences(s);
    for (int i = 0; i < v.size(); i ++)
        cout << v[i] << endl;
    vector<string> vv = ss.findRepeatedDnaSequences(t);
    for (int i = 0; i < vv.size(); i ++)
        cout << vv[i] << endl;
    return 0;
}
