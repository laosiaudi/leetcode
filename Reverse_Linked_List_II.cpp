// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Reverse_Linked_List_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-27 00:11:05
// MODIFIED: 2015-04-27 00:51:29
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if (head == NULL || m == n)
                return head;
            
            ListNode* helper = new ListNode(0);
            helper->next = head;
            ListNode* walker = helper;
            ListNode* last = helper;
            for (int i = 1; i <= m; i ++) {
                walker = walker->next;
                if (i == m - 1)
                    last = walker;
            }
            
            ListNode* end;
            ListNode* before = walker;
            ListNode* newEnd = walker;
            for (int i = m; i <= n; i ++) {
                ListNode* temp = walker->next;
                if (i > m) {
                    walker->next = before;
                    before = walker;
                }
                if (i == n)
                    end = walker;
                walker = temp;
            }
            last->next = end;
            newEnd->next =walker;
            head = helper->next;
            delete helper;
            return head;
        }
};

int main() {
    ListNode* first = new ListNode(3);
    ListNode* second = new ListNode(5);
    first->next = second;
    Solution s;
    ListNode* head = s.reverseBetween(first, 1, 2);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
