// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Min_Stack.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-31 21:34:24
// MODIFIED: 2015-05-31 22:25:44
#include <iostream>
using namespace std;


class MinStack {
    public:
        void push(int x) {
           if (v.size() == 0)
               minEle = x;
           else
               minEle = minEle < x? minEle : x;
           v.push_back(x);
        }

        void pop() {
            int temp = v[v.size() - 1];
            v.pop_back();
            if (temp != minEle)
                return ;
            int minTemp = v[0];
            for (int i = 1; i < v.size();i ++) {
                if (v[i] < minTemp)
                    minTemp = v[i];
            }
            minEle = minTemp;
        }

        int top() {
            return v[v.size() - 1]; 
        }

        int getMin() {
            return minEle;
        }
    private:
        vector<int>v;
        int minEle;
};

class AnotherSolution {
    public:
        void push(int x) {
           if (minStack.size() == 0 || x <= minStack.top())
               minStack.push(x);
           v.push_back(x);
        }

        void pop() {
           if (minStack.top() == v[v.size() - 1])
               minStack.pop();
           v.pop_back();
        }

        int top() {
            return v[v.size() - 1];
        }

        int getMin() {
            return minStack.top();
        }
    private:
        vector<int>v;
        stack<int>minStack;
};
