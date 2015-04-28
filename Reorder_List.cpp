// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Reorder_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-28 13:10:11
// MODIFIED: 2015-04-28 13:49:29
#include <iostream>
#include <stack>
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
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        void reorderList(ListNode *head) {
            if(head == NULL || head->next == NULL)
                return ;

            ListNode* helper = new ListNode(0);
            helper->next = head;
            ListNode* walker = helper;
            ListNode* runner = helper;
            while (runner != NULL && runner->next != NULL) {
                walker = walker->next;
                runner = runner->next->next;
            }

            stack<ListNode*>s;
            while (walker->next != NULL) {
               walker = walker->next;
               s.push(walker);
            }

            walker = head;
            while (!s.empty()) {
                ListNode* newNode = s.top();
                s.pop();
                ListNode* temp = walker->next;
                walker->next = newNode;
                newNode->next = temp;
                walker = temp;
            }
            walker->next = NULL;
            delete helper;
        }
};

//也可以找到链表中点后，将后半段链表发转，再合并两个链表

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Solution s;
    s.reorderList(n1);
    ListNode* temp = n1;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }
    return 0;
}
