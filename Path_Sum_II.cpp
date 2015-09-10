/*********************************************************************************
*     File Name           :     Path_Sum_II.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-10 15:21]
*     Last Modified       :     [2015-09-10 15:30]
*     Description         :
**********************************************************************************/

/**
 *  Definition for a binary tree node.
 * *    struct TreeNode {
 *          int val;
 *          TreeNode *left;
 *          TreeNode *right;
 *          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *      };
 *  */
class Solution {
    public:
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int>> v;
            if (root == NULL)
                return v;
            vector<int>tmpV;
            getSum(root, 0, sum, v, tmpV);
            return v;
        }

        void getSum(TreeNode* root, int tmp, int sum, vector<vector<int>> &v,
                vector<int>tmpV) {
            if (root == NULL)
                return;
            if (root->left == NULL && root->right == NULL) {
                if (tmp + root->val == sum) {
                    tmpV.push_back(root->val);
                    v.push_back(tmpV);
                }
                return;
            }

            tmpV.push_back(root->val);
            getSum(root->left, tmp + root->val, sum, v, tmpV);
            getSum(root->right, tmp + root->val, sum, v, tmpV);
            return;
        }
};

