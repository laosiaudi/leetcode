// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Binary_Search_Tree_Iterator.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-02 17:36:07
// MODIFIED: 2015-06-02 17:45:10
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
class BSTIterator {
    public:
        BSTIterator(TreeNode *root) { //get inorder traversal
            v = inorderTraversal(root);
            index = 0;
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            if (v.size() == 0)
                return false;
            else
                return index < v.size();
        }

        /** @return the next smallest number */
        int next() {
            int temp = index;
            index ++;
            return v[temp];

        }
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
    private:
        vector<int>v;
        int index;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
