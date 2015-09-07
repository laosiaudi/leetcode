/*********************************************************************************
*     File Name           :     Balanced_Binary_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-07 11:30]
*     Last Modified       :     [2015-09-07 11:48]
*     Description         :
**********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if (root == NULL)
                return true;
            int lh = getHeight(root->left);
            if (lh == -1)
                return false;
            int rh = getHeight(root->right);
            if (rh == -1)
                return false;
            return abs(lh - rh) <= 1;
        }

        int getHeight(TreeNode* node) {
            if (node == NULL)
                return 0;

            int lh = getHeight(node->left);
            int rh = getHeight(node->right);
            if (lh == -1 || rh == -1)
                return -1;
            if (abs(lh - rh) > 1)
                return -1;
            return (lh > rh ? lh : rh) + 1;
        }
};


