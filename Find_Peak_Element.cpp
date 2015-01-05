// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Find_Peak_Element.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-05 16:15:40
// MODIFIED: 2015-01-05 16:32:02
#include <iostream>
using namespace std;

class Solution {
    public:
        int findPeakElement(const vector<int> &num) {
           int length = num.size();
           if (length == 1)
               return 0;
           return findByRecursive(num, 0, length - 1);
        }

        int findByRecursive(const vector<int>&A, int start, int end) {
            if (start == end) {
                if (start == 0) {
                    return (A[0] > A[1]?0:-1);
                } else if (start == A.size() - 1) {
                    return (A[start] > A[start - 1]?start:-1);
                } else {
                    return (A[start] > A[start - 1] && A[start] > A[start + 1])?start:-1;
                }
            } else {
                int pivot = (start + end)/2;
                int resultLeft = findByRecursive(A, start, pivot);
                if (resultLeft != -1)
                    return resultLeft;
                int resultRight = findByRecursive(A, pivot + 1, end);
                if (resultRight != -1)
                    return resultRight;
            }
        }
};
