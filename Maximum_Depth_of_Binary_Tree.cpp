/*********************************************************************************
*     File Name           :     Minimum_Depth_of_Binary_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-10 16:14]
*     Last Modified       :     [2015-09-10 16:35]
*     Description         :
**********************************************************************************/

/**
 *      Definition for a binary tree node.
 *         struct TreeNode {
 *             int val;
 *             TreeNode *left;
 *             TreeNode *right;
 *             TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 * */
class Solution {
    public:
     int maxDepth(TreeNode *root) {
     // Start typing your C/C++ solution below
     // DO NOT write int main() function
        if(root == NULL)
            return 0;
        int lmin = maxDepth(root->left);
        int rmin = maxDepth(root->right);
        if(lmin ==0 && rmin ==0)
          return 1;
        if(lmin ==0) {
           lmin = INT_MIN;
        }
        if(rmin ==0){
           rmin = INT_MIN;
        }
        return max(lmin, rmin) +1;
     }
};


