/*********************************************************************************
*     File Name           :     Same_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-05 21:57]
*     Last Modified       :     [2015-09-05 22:10]
*     Description         :
**********************************************************************************/

/**
 *   Definition for a binary tree node.
 *   struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *   };
 *    */
#include <iostream>
using namespace std;
class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            return recursiveJudge(p, q);
        }

        bool recursiveJudge(TreeNode* p, TreeNode* q) {
            if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
                return false;
            if (p == NULL && q == NULL)
                return true;
            if (p->val != q->val)
                return false;
            bool left = recursiveJudge(p->left, q->left);
            if (left == false)
                return false;
            return recursiveJudge(p->right, q->right);
        }
};




