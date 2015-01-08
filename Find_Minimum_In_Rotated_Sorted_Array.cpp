// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Find_Minimum_In_Rotated_Sorted_Array.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-08 20:09:54
// MODIFIED: 2015-01-08 20:43:46
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        #define SpecialNum 999999
        int findMin(vector<int> &num) {
           int length = num.size();
           if (length == 1)
               return num[0];
           int result = findByRecursive(num, 0, length - 1);
           if (result == SpecialNum)
               return num[0];
           else
               return result;
        }

        int findByRecursive(const vector<int>&A, int start, int end) {
            if (start == end) {
                if (start == 0) {
                    return (A[0] > A[1]?A[1]:SpecialNum);
                } else if (start == A.size() - 1) {
                    return (A[start] < A[start - 1]?A[start]:SpecialNum);
                } else {
                    return (A[start] > A[start - 1] && A[start] > A[start + 1])?A[start + 1]:SpecialNum;
                }
            } else {
                int pivot = (start + end)/2;
                int resultLeft = findByRecursive(A, start, pivot);
                if (resultLeft != SpecialNum)
                    return resultLeft;
                int resultRight = findByRecursive(A, pivot + 1, end);
                if (resultRight != SpecialNum)
                    return resultRight;
                return SpecialNum;
            }
        }
};

int main() {
    Solution s;
    vector<int>num;
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    cout << s.findMin(num) << endl;
    return 0;
}
