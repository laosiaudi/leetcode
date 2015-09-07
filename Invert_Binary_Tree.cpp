/*********************************************************************************
*     File Name           :     Invert_Binary_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-07 13:57]
*     Last Modified       :     [2015-09-07 14:02]
*     Description         :
**********************************************************************************/

/**
 * Definition for a binary tree node.
 *      struct TreeNode {
 *          int val;
 *          TreeNode *left;
 *          TreeNode *right;
 *          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 * */
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if (root == NULL)
                return NULL;
            TreeNode* oldLeft = root->left;
            TreeNode* oldRight = root->right;

            root->left = invertTree(oldRight);
            root->right = invertTree(oldLeft);
            return root;
        }
};


