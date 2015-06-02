// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Binary_Tree_Postorder_Traversal.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-02 17:17:25
// MODIFIED: 2015-06-02 17:34:49
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
    public: //modify original structure
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int>res;
            if (root == NULL)
                return res;
            stack<TreeNode*>s;
            s.push(root);
            while (!s.empty()) {
                TreeNode* tn = s.top();
                s.pop();
                TreeNode* ln = tn->left;
                TreeNode* rn = tn->right;
                tn->left = NULL;
                tn->right = NULL;
                if (ln == NULL && rn == NULL) {
                    res.push_back(tn->val);
                } else {
                    s.push(tn);
                }
                if (rn)
                    s.push(rn);
                if (ln)
                    s.push(ln);
            }
            return res;
        }
};

class BetterSolution {
    public://do not modify the tree structure
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int>res;
            stack<int>resStack;
            if (root == NULL)
                return res;
            stack<TreeNode*>s;
            s.push(root);
            while (!s.empty()) {
                TreeNode* tn = s.top();
                s.pop();
                TreeNode* ln = tn->left;
                TreeNode* rn = tn->right;
                resStack.push(tn->val);
                if (ln)
                    s.push(ln);
                if (rn)
                    s.push(rn);
            }
            while (!resStack.empty()) {
                res.push_back(resStack.top());
                resStack.pop();
            }
            return res;
            
        }
};
