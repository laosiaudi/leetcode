// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Search_In_Rotated_Sorted_Array.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-30 11:25:08
// MODIFIED: 2015-04-23 17:20:04
#include <iostream>
using namespace std;

class Solution {
    public:
        int search(int A[], int n, int target) {
            if (n == 0)
                return -1;

            int start = 0;
            int end = n - 1;
            int middle = (0 + n - 1)/2;
            while (start <= end) {
                if (A[middle] == target)
                    return middle;
                if (A[middle] < A[end]) {  //右边为升序
                    if (target > A[middle] && target <= A[end])
                        start = middle + 1;
                    else
                        end = middle - 1;
                } else { //左边为升序
                    if (target < A[middle] && target >= A[start])
                        end = middle - 1;
                    else
                        start = middle + 1;
                }
                middle = (start + end)/2;
            }
            return -1;

        }

};
