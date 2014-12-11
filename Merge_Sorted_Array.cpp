// C/C++ File
// AUTHOR:   laosi
// FILE:     Merge_Sorted_Array.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-11 18:36:48
// MODIFIED: 2014-12-11 18:59:05
#include <iostream>
using namespace std;

class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            int *C = new int [m + n];
            int i, j;
            int index = 0;
            for (i = 0, j = 0;i < m && j < n;) {
               if (A[i] < B[j]) {
                C[index ++] = A[i ++];
               } else {
                C[index ++] = B[j ++];
               }
            }

            if (i == m) {
                for (; index < n + m; index ++)
                    C[index] = B[j ++];
            } else {
                for (; index < m + n; index ++)
                    C[index] = A[i ++];
            }
            for (i = 0;i < m + n; i ++) {
                A[i] = C[i];
            }
            delete []C;
        }
};

int main() {
    Solution s;
    int a[100] = {};
    int b[1] = {2};
    s.merge(a, 0, b, 1);
    return 0;
}
