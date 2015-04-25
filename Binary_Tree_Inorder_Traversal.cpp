// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Binary_Tree_Inorder_Traversal.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-25 21:11:41
// MODIFIED: 2015-04-25 21:14:42
#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int>v;
        if (root == NULL)
            return v;
        recursiveTraversal(v, root->left);
        v.push_back(root->val);
        recursiveTraversal(v, root->right);
        return v;
    }

    void recursiveTraversal(vector<int> &v, TreeNode *root) {
        if (root == NULL)
            return;
        recursiveTraversal(v, root->left);
        v.push_back(root->val);
        recursiveTraversal(v,root->right);
    }
};
