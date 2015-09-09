/*********************************************************************************
*     File Name           :     Validate_Binary_Search_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-09 00:05]
*     Last Modified       :     [2015-09-09 00:39]
*     Description         :
**********************************************************************************/

/**
 *  Definition for a binary tree node.
 *  struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * * };
 *  */
class Solution {
    public:
        //in-order traversal and see if it is increasing
        bool isValidBST(TreeNode* root) {
            vector<int>v;
            inorderTraverse(root, v);
            int n = v.size();
            if (n <= 1)
                return true;
            for (int i = 1; i < n; i ++) {
                if (v[i] <= v[i - 1])
                    return false;
            }
            return true;
        }

        void inorderTraverse(TreeNode* root, vector<int>& v) {
            if (root == NULL)
                return;
            inorderTraverse(root->left, v);
            v.push_back(root->val);
            inorderTraverse(root->right, v);
            return;
        }

        //recursive method
        //pass min and max to every subtree
        //reference:http://fisherlei.blogspot.com/2013/01/leetcode-validate-binary-search-tree.html
        bool isValidBST(TreeNode* root) {
            return ISValidBST(root, LONG_MIN, LONG_MAX);
        }

        bool ISValidBST(TreeNode* root, long min, long max) {
            if (root == NULL)
                return true;
            if (root->val > min
               && root->val < max
               && ISValidBST(root->left, min, root->val)
               && ISValidBST(root->right, root->val, max))
                return true;
            else
                return false;
        }
};


