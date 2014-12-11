// C/C++ File
// AUTHOR:   laosi
// FILE:     Remove_Element.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-12 00:17:18
// MODIFIED: 2014-12-12 00:24:18
#include <iostream>
using namespace std;

class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int num = 0;
            int *a = new int [n];
            int index = 0;
            for (int i = 0;i < n;i ++) {
               if (A[i] == elem)
                   num ++;
               else {
                   a[index ++] = A[i];
               }
            }
            for (int i = 0;i < n - num; i ++)
                A[i] = a[i];
            delete []a;
            return n - num;
        }

};
