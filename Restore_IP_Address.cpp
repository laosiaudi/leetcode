// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Restore_IP_Address.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-15 22:42:22
// MODIFIED: 2015-05-15 23:28:50
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            int size = s.size();
            vector<string>v;
            if (size < 4)
                return v;
            vector<string>ip;
            recursiveRestore(v, 0, s, size, 0, ip);
            return v;
        }

        void recursiveRestore(vector<string> &v, int start, string s, int size, int num, vector<string> &ip) {

            if (start == size && num < 4)
                return;
            if (num == 4 && start != size)
                return;

            if (num == 4 && start == size) {
                string temp = ip[0];
                for (int i = 1; i < 4; i ++)
                    temp = temp + "." + ip[i];
                v.push_back(temp);
                return ;
            }
            int step;
            if (s[start] == '0')
                step = 0;
            else
                step = 2;
            for (int i = 0; i <= step; i ++) {
                int res = 0;
                bool flag = true;
                for (int j = 0; j <= i; j ++) {
                    if (start + j >= size) {
                        return;
                    }
                    res = 10 * res + s[start + j] - '0';
                }
                if (res > 255 || res < 0)
                    continue;
                else {
                    ip.push_back(s.substr(start, i + 1));
                    recursiveRestore(v, start + i + 1, s, size, num + 1, ip);
                    ip.pop_back();
                }
            }
        }
};

int main () {
    Solution s;
    s.restoreIpAddresses("100100");
    return 0;
}
