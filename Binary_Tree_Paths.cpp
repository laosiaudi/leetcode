/*********************************************************************************
*     File Name           :     Binary_Tree_Paths.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-07 13:03]
*     Last Modified       :     [2015-09-07 13:19]
*     Description         :
**********************************************************************************/

/**
 *  Definition for a binary tree node.
 *  struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string>v;
            if (root == NULL)
                return v;

            string tmp = "";
            tmp += to_string(root->val);
            computePath(root, tmp, v);
            return v;
        }

        void computePath(TreeNode* root, string tmp, vector<string> &v) {
            if (root->left == NULL && root->right == NULL) {
                v.push_back(tmp);
                return;
            }
            if (root->left != NULL)
                computePath(root->left, tmp + "->" + to_string(root->left->val), v);
            if (root->right != NULL)
                computePath(root->right, tmp + "->" + to_string(root->right->val), v);
        }
};


