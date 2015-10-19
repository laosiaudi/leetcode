/*********************************************************************************
*     File Name           :     Count_Complete_Tree_Nodes.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-18 23:33]
*     Last Modified       :     [2015-10-18 23:57]
*     Description         :
**********************************************************************************/

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */

//TLE
class Solution {
    public:
        int countNodes(TreeNode* root) {
            queue<TreeNode*>q;
            int cnt = 0;
            if (root != NULL)
                q.push(root);
            while (!q.empty()) {
                TreeNode* tmp = q.front();
                q.pop();
                cnt ++;
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
            }
            return cnt;
        }
};


class BetterSolution {
    public:
        int countNodes(TreeNode* root) {
            int depth = 0;
            TreeNode* node = root;
            while (node) {
                depth ++;
                node = node->left;
            }
            if (depth == 0)
                return 0;


            int left = 0;
            int right = (1 << (depth - 1)) - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (getNode(root, mid, depth))
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            return (1 << (depth - 1)) + right;
        }

        bool getNode(TreeNode* root, int cnt, int depth) {
            for (int i = depth - 2; i >= 0; i --) {
                if (cnt & (1 << i))
                    root = root->right;
                else
                    root = root->left;
            }
            return root != NULL;
        }
};
