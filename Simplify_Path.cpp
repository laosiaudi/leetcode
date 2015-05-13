// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Simplify_Path.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-14 00:28:20
// MODIFIED: 2015-05-14 01:48:17
#include <iostream>
using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            int size = path.size();
            stack<string>ss;
            string temp;
            for (int i = 0; i < size;) {
                while (path[i] == '/' && i < size)
                    i ++;
                if (i == size)
                    break;
                int start = i;
                while (path[i] != '/' && i < size)
                    i ++;
                int end = i -1;
                string element = path.substr(start, end-start+1);  
                if (element == "..") {
                    if (!ss.empty())
                        ss.pop();
                } else if (element != ".")
                    ss.push(element);

            }
            string res = "/";
            while (!ss.empty()) {
                if (res == "/")
                    res = res + ss.top();
                else 
                    res = "/" + ss.top() + res;
                ss.pop();
            }
            return res;
        }
};
