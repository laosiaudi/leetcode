/*********************************************************************************
*     File Name           :     Minimum_Depth_of_Binary_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-10 16:14]
*     Last Modified       :     [2015-09-10 16:31]
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
        int minDepth(TreeNode* root) {
            if (root == NULL)
                return 0;
            int tmp = 1;
            queue<TreeNode*>q;
            q.push(root);
            while (!q.empty()) {
                int len = q.size();
                for (int i = 0; i < len; i ++) {
                    TreeNode* tmn = q.front();
                    q.pop();
                    if (tmn->left == NULL && tmn->right == NULL)
                        return tmp;
                    else {
                        if (tmn->left != NULL)
                            q.push(tmn->left);
                        if (tmn->right != NULL)
                            q.push(tmn->right);
                    }
                }
                tmp ++;
            }
            return tmp;
        }


        //another solution
     int minDepth(TreeNode *root) {
     // Start typing your C/C++ solution below
     // DO NOT write int main() function
        if(root == NULL)
            return 0;
        int lmin = minDepth(root->left);
        int rmin = minDepth(root->right);
        if(lmin ==0 && rmin ==0)
          return 1;
         if(lmin ==0) {
           lmin = INT_MAX;
         }
         if(rmin ==0){
           rmin = INT_MAX;
         } return min(lmin, rmin) +1;
     }
};


