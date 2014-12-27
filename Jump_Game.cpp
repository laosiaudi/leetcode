// C/C++ File
// AUTHOR:   laosi
// FILE:     Jump_Game.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-15 23:47:47
// MODIFIED: 2014-12-16 02:17:29
#include <iostream>
using namespace std;

class Solution { //greedy
    public:
        bool canJump(int A[], int n) {
            int maxStep = 0;
            for (int start = 0; start <= maxStep && start < n; start ++) {
                if (A[start] + start > maxStep)
                    maxStep = A[start] + start;
                if (maxStep >= n - 1)
                    return true;
            }
            return false;
        }


};

int main () {
    Solution s;
    int a[] = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    int *b = new int [25000];
    for (int i = 0; i < 25000; i ++)
        b[i] = 25000 - i;
    if (s.canJump(b, 25000))
        cout << "Yes\n";
    return 0;
}
