// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Merge_k_Sorted_Lists.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-28 15:00:26
// MODIFIED: 2015-04-28 15:46:18
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
        //使用merge_two_sorted_lists，两个两个合并 -- TLE
        ListNode* mergeKLists_TLE(vector<ListNode*>& lists) {
            int size = lists.size();
            if (size == 0)
                return NULL;
            ListNode* pre = lists[0];
            for (int i = 1;i < size; i ++) {
                pre = mergeTwoLists(pre, lists[i]);
            }
            return pre;
        }
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

        //use priority_queue(head) to contain the first element of each list, every time take the smallest one
        //from the heap to be inserted into the long list, and take its next element into the heap
        struct cmp {
			bool operator ()(const ListNode *a, const ListNode *b) {
            return a->val > b->val;
            }
        };

        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int size = lists.size();
            if (size == 0)
                return NULL;

            ListNode* helper = new ListNode(0);
            ListNode* res = helper;
            priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        
        	for(int i = 0; i < size; i++)
            	if(lists[i])
                	que.push(lists[i]);
        	
        	while(!que.empty()) {
            	ListNode * p = que.top();
            	que.pop();
            	res->next = p;
            	res = p;
             
            	if(p->next)
                	que.push(p->next);
        	}
            ListNode* head = helper->next;
        	return head;

        }
};
