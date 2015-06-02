// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Binary_Tree_Preorder_Traversal.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-02 17:00:48
// MODIFIED: 2015-06-02 17:15:33
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int>res;
            if (root == NULL)
                return res;
            stack<TreeNode*>s;
            s.push(root);

            while (!s.empty()) {
                TreeNode* temp = s.top();
                s.pop();
                res.push_back(temp->val);
                if (temp->right)
                    s.push(temp->right);
                if (temp->left)
                    s.push(temp->left);
            }

            return res;
        }
};
