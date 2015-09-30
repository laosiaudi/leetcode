/*********************************************************************************
*     File Name           :     Palindrome_Linked_List.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-30 13:56]
*     Last Modified       :     [2015-09-30 14:36]
*     Description         :
**********************************************************************************/

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if (head == NULL)
                return true;
            if (head->next == NULL)
                return true;
            ListNode* fast = head;
            ListNode* slow = head;
            while (fast->next != NULL && fast->next->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }

            ListNode* tmp = slow->next;
            ListNode* pre = tmp;
            tmp = tmp->next;
            pre->next = NULL;
            while (tmp != NULL) {
                ListNode* next = tmp->next;
                tmp->next = pre;
                pre = tmp;
                tmp = next;
            }

            slow = head;
            while (pre != NULL) {
                if (pre->val != slow->val)
                    return false;
                pre = pre->next;
                slow = slow->next;
            }

            return true;


        }
};


