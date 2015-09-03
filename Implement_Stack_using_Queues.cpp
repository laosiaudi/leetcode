// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Implement_Stack_using_Queues.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-08-21 17:24:38
// MODIFIED: 2015-08-21 17:28:01
#include <iostream>
using namespace std;

class Stack {
    public:
        vector<int>q;
        // Push element x onto stack.
        void push(int x) {
            q.push_back(x);
        }
        // Removes the element on top of the stack.
        void pop() {
            q.erase(q.end() - 1);
        }
        // Get the top element.
        int top() {
            return q[q.size() - 1];
        }
        // Return whether the stack is empty.
        bool empty() {
            return q.size() == 0;
        }
};
