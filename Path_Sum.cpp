/*********************************************************************************
*     File Name           :     Path_Sum.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-08 20:35]
*     Last Modified       :     [2015-09-08 20:56]
*     Description         :
**********************************************************************************/

/**
 *  Definition for a binary tree node.
 *      struct TreeNode {
 *          int val;
 *          TreeNode *left;
 *          TreeNode *right;
 *          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 *      */
class Solution {
    public:
        bool hasPathSum(TreeNode* root, int sum) {
            if (root == NULL)
                return false;
            return checkSum(root, 0, sum);
        }

        bool checkSum(TreeNode* root, int tmp, int sum) {
            if (root->left == NULL && root->right == NULL)
                return (tmp + root->val) == sum;

            bool re = false;
            if (root->left)
                re = checkSum(root->left, tmp + root->val, sum);
            if (re)
                return true;

            if (root->right)
                re = checkSum(root->right, tmp + root->val, sum);
            return re;
        }
};


