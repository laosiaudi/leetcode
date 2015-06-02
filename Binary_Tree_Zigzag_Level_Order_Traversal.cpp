// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Binary_Tree_Zigzag_Level_Order_Traversal.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-02 16:20:19
// MODIFIED: 2015-06-02 16:59:26
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int> >res;
            stack<TreeNode*>s;
            if (root == NULL)
                return res;
            else {
                s.push(root);
                recursiveZigZag(res, 0, s);//0 --> left to right
                return res;
            }
        }

        void recursiveZigZag(vector<vector<int> >&v, int bit, stack<TreeNode*> &s) {
            if (s.empty())
                return;
            vector<int>level;
            stack<TreeNode*>temp;
            while (!s.empty()) {
               TreeNode* tn = s.top();
               if (!bit) {
                   if (tn->left)
                       temp.push(tn->left);
                   if (tn->right)
                       temp.push(tn->right);
               } else {
                   if (tn->right)
                       temp.push(tn->right);
                   if (tn->left)
                       temp.push(tn->left);
               }
               level.push_back(tn->val);
               s.pop();
            }
            bit = bit? 0 : 1;
            v.push_back(level);
            s = temp;
            recursiveZigZag(v, bit, temp);
        }

};
