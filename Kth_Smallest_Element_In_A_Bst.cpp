/*********************************************************************************
*     File Name           :     Kth_Smallest_Element_In_A_Bst.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-09 15:12]
*     Last Modified       :     [2015-09-09 15:14]
*     Description         :
**********************************************************************************/
/**
Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */
class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            vector<int>v;
            inorderTraverse(root, v);
            return v[k - 1];

        }
        void inorderTraverse(TreeNode* root, vector<int>& v) {
            if (root == NULL)
                return;
            inorderTraverse(root->left, v);
            v.push_back(root->val);
            inorderTraverse(root->right, v);
            return;
        }
};


