// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Linked_List_Cycle.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-29 17:47:52
// MODIFIED: 2015-04-29 18:05:49
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

// follow up: http://www.cnblogs.com/hiddenfox/p/3408931.html
// follow up:http://www.vimer.cn/2010/10/%E4%B8%80%E9%81%93%E4%B8%8D%E9%94%99%E7%9A%84%E7%AE%97%E6%B3%95%E9%A2%98-%E5%88%A4%E6%96%AD%E9%93%BE%E8%A1%A8%E6%98%AF%E5%90%A6%E6%9C%89%E7%8E%AF.html
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return false;
            ListNode* helper = new ListNode(0);
            helper->next = head;
            ListNode* walker = helper;
            ListNode* runner = helper;
            while (walker != NULL && runner != NULL && walker->next != NULL && runner->next != NULL) {
                walker = walker->next;
                runner = runner->next->next;
                if (walker ==  runner) {
                    delete helper;
                    return true;
                }
            }

            return false;
        }
};
