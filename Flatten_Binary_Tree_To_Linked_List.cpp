/*********************************************************************************
*     File Name           :     Flatten_Binary_Tree_To_Linked_List.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-08 20:14]
*     Last Modified       :     [2015-09-08 20:33]
*     Description         :
**********************************************************************************/

/**
 *  Definition for a binary tree node.
 *      struct TreeNode {
 *          int val;
 *          TreeNode *left;
 *          TreeNode *right;
 *          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 *     */
class Solution {
    public:
        void flatten(TreeNode* root) {
            if (root == NULL)
                return;
            stack<TreeNode*>s;
            s.push(root);


            TreeNode* walker = new TreeNode(-1);
            TreeNode* head = walker;
            while (!s.empty()) {
                TreeNode* tmp = s.top();
                s.pop();
                walker->right = tmp;
                walker->left = NULL;
                walker = tmp;
                if (tmp->right != NULL)
                    s.push(tmp->right);
                if (tmp->left != NULL)
                    s.push(tmp->left);
            }
            delete []head;
        }
};


