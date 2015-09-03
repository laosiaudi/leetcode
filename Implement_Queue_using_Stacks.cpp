// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Implement_Queue_using_Stacks.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-08-21 17:17:31
// MODIFIED: 2015-08-21 17:22:53
#include <iostream>
using namespace std;

class Queue {
    public:
        vector<int>s;
        // Push element x to the back of queue.
        void push(int x) {
            s.push_back(x);
        }
        // Removes the element from in front of queue.
        void pop(void) {
            s.erase(s.begin());
        }
        // Get the front element.
        int peek(void) {
            return s.front();
        }
        // Return whether the queue is empty.
        bool empty(void) {
            return s.size() == 0;
        }
};
