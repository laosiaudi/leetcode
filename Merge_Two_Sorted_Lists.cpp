// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Merge_Two_Sorted_Lists.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-28 14:15:48
// MODIFIED: 2015-04-28 15:02:21
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
    	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
             if (l1 == NULL)
                 return l2;
             if (l2 == NULL)
                 return l1;
            
             ListNode* head1 = l1;
             ListNode* head2 = l2;
             ListNode* helper = new ListNode(0);
             helper->next =l1;
             ListNode* pre = helper;
             while (head1 != NULL && head2 != NULL) {
                 if (head1->val < head2 -> val) {
                    head1 = head1->next;
                    pre = pre->next;
                 } else {
                    pre->next = head2;
                    ListNode* temp = head2->next;
                    head2->next = head1;
                    head2 = temp;
                    pre = pre->next;
                 }
             }
             if (head2 != NULL)
                 pre->next = head2;
             l1 = helper->next;
             return l1;
    	}
};
