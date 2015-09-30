/*********************************************************************************
*     File Name           :     Binary_Tree_Maximum_Path_Sum.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-30 01:57]
*     Last Modified       :     [2015-09-30 11:15]
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
        int maxPathSum(TreeNode* root) {
            int max_val = INT_MIN;
            int reval = recursiveMax(root, max_val);
            return max_val;
        }

        int recursiveMax(TreeNode* root, int &max_val) {
            if (root == NULL) {
                return 0;
            }

            int left_reval;
            left_reval = recursiveMax(root->left, max_val);

            int right_reval;
            right_reval = recursiveMax(root->right, max_val);

            int tmp = root->val;
            if (left_reval > 0)
                tmp += left_reval;
            if (right_reval > 0)
                tmp += right_reval;
            max_val = max_val > tmp ? max_val : tmp;

            return max(root->val, max(root->val + left_reval, root->val + right_reval));
        }
};


