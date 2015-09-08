/*********************************************************************************
*     File Name           :     Sum_Root_To_Leaf_Numbers.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-08 14:48]
*     Last Modified       :     [2015-09-08 14:58]
*     Description         :
**********************************************************************************/

/**
 *  Definition for a binary tree node.
 *  struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 * */
class Solution {
    public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum = 0;
        int temp = 0;
        getSum(root, sum, root->val);
        return sum;
    }

    void getSum(TreeNode* root, int &sum, int temp) {
        if (root->left == NULL && root->right == NULL) {
            sum += temp;
            return;
        }

        if (root->left)
            getSum(root->left, sum, temp*10 + root->left->val);
        if (root->right)
            getSum(root->right, sum, temp*10 + root->right->val);

    }

};


