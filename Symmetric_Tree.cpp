/*********************************************************************************
*     File Name           :     Symmetric_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-08 13:51]
*     Last Modified       :     [2015-09-08 16:50]
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
        bool isSymmetric(TreeNode* root) {
            if (root == NULL)
                return true;
            vector<TreeNode*>v;
            v.push_back(root);
            int level = 1;

            while (level > 0) {
                int i = 0;
                while (i < level) {
                    TreeNode* tmp = v[i];
                    i ++;

                    if (tmp == NULL)
                        continue;
                    v.push_back(tmp->left);
                    v.push_back(tmp->right);
                }

                int start = 0, end = level - 1;
                while (start < end) {
                    TreeNode* lc = v[start];
                    TreeNode* rc = v[end];
                    int vlc = lc == NULL ? -1 : lc->val;
                    int vrc = rc == NULL ? -1 : rc->val;
                    if (vlc != vrc)
                        return false;
                    start ++;
                    end --;
                }
                v.erase(v.begin(), v.begin() + level);
                level = v.size();
            }
            return true;
        }

        //recursive version
        bool isSymmetric(TreeNode* root) {
            if (root == NULL)
                return true;
            return isReSymmetric(root->left, root->right);
        }

        bool isReSymmetric(TreeNode* left, TreeNode* right) {
            if (left == NULL)
                return right == NULL;
            if (right == NULL)
                return left == NULL;

            if (left->val != right->val)
                return false;
            if (!isReSymmetric(left->left, right->right))
                return false;
            if (!isReSymmetric(left->right, right->left))
                return false;
            return true;
        }
};


