/*********************************************************************************
*     File Name           :     Delete_Node_In_A_Linked_List.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-06 20:50]
*     Last Modified       :     [2015-09-06 20:58]
*     Description         :
**********************************************************************************/

/**
 *  Definition for singly-linked list.
 *  struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *  };
 *  */
class Solution {
    public:
        void deleteNode(ListNode* node) {
            if (node == NULL)
                return;
            node->val = node->next->val;
            ListNode* tmp = node->next;
            node->next = node->next->next;
            delete tmp;
            return;
        }
};


