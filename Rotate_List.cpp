// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Rotate_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-26 23:11:40
// MODIFIED: 2015-04-27 00:10:11
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if (head == NULL || k == 0)
                return head;
            ListNode* walker = head;
            ListNode* tail;
            int size = 0;
            while (walker != NULL) {
                size ++;
                if (walker->next == NULL)
                    tail = walker;
                walker = walker->next;
            }
            k = k % size;
            if (size == 1 || k == size || k == 0)
                return head;
            
            ListNode* newhead;
            int index = 1;
            walker = head;
            while (index != size - k) {
                walker = walker->next;
                index ++;
            }
            newhead = walker->next;
            walker->next = NULL;
            tail->next = head;
            head = newhead;
            return head;
            
        }
};

//也可以 首先从head开始跑，直到最后一个节点，这时可以得出链表长度len。然后将尾指针指向头指针，将整个圈连起来，接着往前跑len – k%len，从这里断开，就是要求的结果了。

