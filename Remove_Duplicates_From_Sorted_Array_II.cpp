// C/C++ File
// AUTHOR:   laosi
// FILE:     Remove_Element_From_Sorted_Array.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-12 00:25:25
// MODIFIED: 2014-12-11 23:13:49
#include <iostream>
using namespace std;

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
           int index = 1;
           int count = 1;
           for (int i = 1;i < n;i ++) {
                if (A[i] == A[i - 1]) {
                    if (count < 2) {
                        A[index ++] = A[i];
                        count ++;
                    } else {
                        continue;
                    }
                }
                else {
                    A[index ++] = A[i];
                    count = 1;
                }
           }
           if (n == 0)
               return 0;
           else
               return index;
        }

};


int main() {
    int a[10] = {1,1,1,3,3,4,6,6,6,7};
    int b[5] = {1,2,3,4,5};
    Solution s;
    int t = s.removeDuplicates(a, 10);
    for (int i = 0;i < t; i ++)
        cout << a[i];
    cout << endl;
    t = s.removeDuplicates(b, 5);
    for (int i = 0;i < t; i ++)
        cout << b[i];
    cout << endl;
    return 0;
}
