// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Convert_Sorted_List_To_Binary_Search_Tree.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-30 15:25:48
// MODIFIED: 2015-04-30 15:58:35
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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            if (head == NULL)
                return NULL;
            ListNode* walker = head;
            ListNode* runner = head->next;
            while (walker != NULL && runner != NULL && runner->next != NULL) {
                walker = walker->next;
                runner = runner->next->next;
            }
            TreeNode* root = new TreeNode(walker->val);
            TreeNode* leftNode = recursiveBuild(head, walker);
            TreeNode* rightNode = recursiveBuild(walker->next, NULL);
            root->left = leftNode;
            root->right = rightNode;
            return root;
        }

        TreeNode* recursiveBuild(ListNode* head, ListNode* end) {
            if (head == end)
                return NULL;
            ListNode* walker = head;
            ListNode* runner = head->next;
            while (walker != end && runner != end && runner->next != end) {
                walker = walker->next;
                runner = runner->next->next;
            }
            TreeNode* root = new TreeNode(walker->val);
            TreeNode* leftNode = recursiveBuild(head, walker);
            TreeNode* rightNode = recursiveBuild(walker->next, end);
            root->left = leftNode;
            root->right = rightNode;
            return root;
        }
};
