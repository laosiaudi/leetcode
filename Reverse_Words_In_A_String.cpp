// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Reverse_Words_In_A_String.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-14 23:03:16
// MODIFIED: 2015-05-14 23:27:03
#include <iostream>
using namespace std;

class Solution {
    public:
    void reverseWords(string &s) {
       int size = s.size();
       if (size == 0)
           return;
       stack<string>ss;

       string res;
       for (int i = 0; i < size;) {
           while (s[i] == ' ' && i < size)
               i ++;
           if (i == size)
               break;
           int start = i;
           while (s[i] != ' ' && i < size)
               i ++;
           int end = i;
           string element = s.substr(start, end - start);
           ss.push(element);
       }

       while (ss.size() > 1) {
           res = res + ss.top() + " ";
           ss.pop();
       }
       if (ss.size() == 1)
           res += ss.top();
       s = res;
    }
};

//if want to O(1) in-place, first reverse the whole string, and then reverse every word
//reverse a string can use in-place way: swap the chars of s[i] and s[len - 1 -n]
