/*********************************************************************************
*     File Name           :     Binary_Tree_Right_Side_View.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-08 19:30]
*     Last Modified       :     [2015-09-08 20:10]
*     Description         :
**********************************************************************************/

/**
 *   Definition for a binary tree node.
 *  * struct TreeNode {
 *          int val;
 *          TreeNode *left;
 *          TreeNode *right;
 *          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *   };
 *  */
class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int>v;
            if (root == NULL)
                return v;
            int tmp = 1;
            v.push_back(root->val);
            getRightSide(v, tmp + 1, root->right);
            getRightSide(v, tmp + 1, root->left);
            return v;
        }

        void getRightSide(vector<int> &v, int tmp, TreeNode* root) {
            if (root == NULL) {
                return;
            }

            int len = v.size();
            if (tmp > len) {
                v.push_back(root->val);
            }

            getRightSide(v, tmp + 1, root->right);
            getRightSide(v, tmp + 1, root->left);
            return;
        }

        vector<int> betterRightSideView(TreeNode* root) {
            vector<int>v;
            if (root == NULL)
                return v;
            queue<TreeNode*>q;
            q.push(root);

            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i ++) {
                    TreeNode* tmp = q.front();
                    q.pop();
                    if (i == 0)
                        v.push_back(tmp->val);
                    if (tmp->right)
                        q.push(tmp->right);
                    if (tmp->left)
                        q.push(tmp->left);
                }
            }

            return v;
        }
};

