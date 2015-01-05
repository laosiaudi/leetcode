// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Search_For_A_Range.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-05 14:53:54
// MODIFIED: 2015-01-05 15:32:56
#include <iostream>
using namespace std;

class Solution {
    public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int>v;
        if (n == 1) {
            if (A[0] == target) {
                v.push_back(0);
                v.push_back(0);
                return v;
            } else {
                v.push_back(-1);
                v.push_back(-1);
                return v;
            }
        }
        int start = binarySearch(A, 0, n - 1, target);
        int end = binarySearch(A, 0, n - 1, target + 1);
        if (A[start] == target && A[end - 1] == target) {
            v.push_back(start);
            v.push_back(end - 1);
        } else {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
    int binarySearch(int A[], int start, int end, int target) {
        if (start == end) {
            if (target <= A[start])
                return start;
            else
                return start + 1;
        }
        int pivot = (start + end)/2;
        int result = -1;
        if (target <= A[pivot])
            result = binarySearch(A, start, pivot, target);
        else
            result = binarySearch(A, pivot + 1, end, target);
        return result;
    }
};
