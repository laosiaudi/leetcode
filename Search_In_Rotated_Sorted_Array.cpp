// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Search_In_Rotated_Sorted_Array.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-30 11:25:08
// MODIFIED: 2015-01-31 12:15:21
#include <iostream>
using namespace std;

class Solution {
    public:
        int search(int A[], int n, int target) {
            if (n == 0)
                return -1;
            return binarySearch(A, 0, n - 1, target);
        }

        int binarySearch(int A[], int start, int end, int target) {
           if (start == end) {
              return (A[start] == target? start : -1);
           }
           int pivot = (start + end)/2;
           if (A[pivot] == target)
              return pivot; 
           int result = -1;
           if (target > A[pivot]) {
              if (pivot + 1 <= end && A[pivot] < A[pivot + 1] && target > A[end])
                  result = binarySearch(A, pivot + 1, end, target);
              else
                  result = binarySearch(A, start, pivot, target);
           } else {
              if (A[start] <= target)
                  result = binarySearch(A, start, pivot, target);
              else
                  result = binarySearch(A, pivot + 1, end, target);
           }
           return result;
        }
};
