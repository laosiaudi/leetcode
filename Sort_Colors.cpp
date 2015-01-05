// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Sort_Colors.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2014-12-27 20:02:40
// MODIFIED: 2015-01-05 14:29:51
#include <iostream>
using namespace std;

//two-pass algorithm
class Solution {
    public:
    void sortColors(int A[], int n) {
        int numOfRed = 0;
        int numOfWhite = 0;
        int numOfBlue = 0;

        for (int i = 0;i < n; i ++) {
            if (A[i] == 0)
                numOfRed ++;
            if (A[i] == 1)
                numOfWhite ++;
            if (A[i] == 2)
                numOfBlue ++;
        }
        int index = 0;
        for (int i = 1; i <= numOfRed; i ++) {
            A[index ++] = 0;
        }

        for (int i = 1; i <= numOfWhite; i ++) {
            A[index ++] = 1;
        }
 
        for (int i = 1; i <= numOfBlue; i ++) {
            A[index ++] = 2;
        }

    }
};


//one-pass algorithm
class Solution {
    public:
        void sortColors(int A[], int n) {
            if (n == 0)
                return ;
            int startOfWhite  = 0;
            int endOfWhite = n - 1;
            int index = 0;

            while (index <= endOfWhite) {
                if (A[index] == 0) {
                    A[index] = A[startOfWhite];
                    A[startOfWhite] = 0;
                    index ++;
                    startOfWhite ++;
                } else if (A[index] == 1) {
                    index ++;
                } else {
                    A[index] = A[endOfWhite];
                    A[endOfWhite] = 2;
                    endOfWhite --;
                }
            }

        }

};
