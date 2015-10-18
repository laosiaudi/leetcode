/*********************************************************************************
*     File Name           :     Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-18 01:08]
*     Last Modified       :     [2015-10-18 01:10]
*     Description         :
**********************************************************************************/
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* walker = root;
            if (walker == NULL)
                return NULL;
            while (walker != NULL) {
                if (walker->val > p->val && walker->val > q->val)
                    walker = walker->left;
                else if (walker->val < p->val && walker->val < q->val)
                    walker = walker->right;
                else
                    return walker;
            }
            return NULL;
        }
};

