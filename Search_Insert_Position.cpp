// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Search_Insert_Position.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-05 14:38:02
// MODIFIED: 2015-01-05 14:53:23
#include <iostream>
using namespace std;

class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            return binarySearch(A, 0, n - 1, target);
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

int main() {
    Solution s;
    int a[4] = {1,3,5,6};
    cout << s.searchInsert(a, 4, 5) << endl;
    cout << s.searchInsert(a, 4, 2) << endl;
    cout << s.searchInsert(a, 4, 7) << endl;
    cout << s.searchInsert(a, 4, 0) << endl;
}
