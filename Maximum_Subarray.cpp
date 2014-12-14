// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Maximum_Subarray.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2014-12-14 13:27:04
// MODIFIED: 2014-12-14 15:20:00
#include <iostream>
using namespace std;

class Solution { //O(n)
    public:
    int maxSubArray(int A[], int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return A[0];

        int sum = A[0];
        int maxEle = A[0];

        for (int i = 1; i < n; i ++) {
            if (sum >= 0) {
                if (A[i] > 0) {
                    sum += A[i];
                    maxEle = sum;
                } else {
                    maxEle = maxEle > sum ? maxEle : sum;
                    sum += A[i];
                }
            } else {
                if (A[i] <= 0) {
                    sum = sum > A[i] ? sum : A[i];
                    maxEle = maxEle > sum ? maxEle : sum;
                } else {
                    sum = A[i];
                    maxEle = maxEle > A[i] ? maxEle : A[i];
                }
            }
        }
        return maxEle > sum ? maxEle : sum;
        /*more subtle way
          sum is for 局部最优(一定含A[i])
          maxEle is for 全局最优
        for (int i = 1; i < n; i ++) {
            sum = A[i] > (sum + A[i]) ? A[i] : (sum + A[i]);
            maxEle = sum > maxEle ? sum : maxEle;
        }
        return maxEle;
        */
    }
};

class Solution { //Divide and Conquer
    public:
        int maxSubArray(int A[], int n) {
            recursiveMaxSubArray(A, 0, n - 1);
        }

        int recursiveMaxSubArray(int A[], int start, int end) {
            if (start == end)
                return A[start];
            int mid = (start + end) / 2;
            int maxLeft = recursiveMaxSubArray(A, start, mid); //max value appears in left part
            int maxRight = recursiveMaxSubArray(A, mid + 1, end); //max value appears in right part

            int leftHalf = 0, rightHalf = 0;
            int leftMax = -99999, rightMax = -99999;
            //start from the mid position, extends to left and right
            for (int i = mid; i >= start; i --) {
                leftHalf += A[i];
                leftMax = leftMax > leftHalf ? leftMax : leftHalf;
            }
            for (int i = mid + 1; i <= end; i ++) {
                rightHalf += A[i];
                rightMax = rightMax > rightHalf ? rightMax : rightHalf;
            }

            int max1 = maxLeft > maxRight ? maxLeft : maxRight;
            int max2 = leftMax + rightMax;
            return max1 > max2 ? max1 : max2;
        }
};
