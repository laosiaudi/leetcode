// C/C++ File
// AUTHOR:   laosi
// FILE:     Maximum_Product_Subarray.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-15 22:34:55
// MODIFIED: 2014-12-15 23:37:56
#include <iostream>
using namespace std;

class Solution {
    public:
        int maxProduct(int A[], int n) {
            if (n == 0)
                return 0;
            if (n == 1)
                return A[0];

            int localMax = A[0];
            int localMin = A[0];
            int maxEle = A[0];
            

            for (int i = 1; i < n; i ++) {
                int tempMax = A[i] > (localMax * A[i]) ? A[i] : (localMax * A[i]);
                int temp = localMax;
                localMax = tempMax > localMin * A[i] ? tempMax : localMin * A[i];
                int tempMin = A[i] < temp * A[i] ? A[i] : temp * A[i];
                localMin = tempMin < localMin * A[i] ? tempMin : localMin * A[i];
                int tempCompare = maxEle > localMax ? maxEle : localMax;
                maxEle = tempCompare > localMin ? tempCompare : localMin;
            }
            return maxEle;
        }

};

int main() {
    Solution s;
    int A[] = {-2, 3, -4};
    cout << s.maxProduct(A, 3) << endl;
    int B[] = {2,-5,-2,-4,3};
    cout << s.maxProduct(B, 5) << endl;
    return 0;
}
