/*********************************************************************************
*     File Name           :     Binary_Tree_Level_Order_Traversal.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-06 19:56]
*     Last Modified       :     [2015-09-06 20:09]
*     Description         :
**********************************************************************************/
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/**
 *    Definition for a binary tree node.
 *    struct TreeNode {
 *          int val;
 *          TreeNode *left;
 *          TreeNode *right;
 *          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *    };
 *    */

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*>q;
            vector<vector<int>>v;

            if (root == NULL)
                return v;
            q.push(root);

            while (!q.empty()) {
                int size = q.size();
                vector<int>tmp;
                for (int i = 0;i < size; i ++) {
                    TreeNode* tmpNode = q.front();
                    if (tmpNode != NULL) {
                        tmp.push_back(tmpNode->val);
                        q.push(tmpNode->left);
                        q.push(tmpNode->right);
                    }
                    q.pop();
                }
                if (tmp.size() != 0)
                    v.push_back(tmp);
            }
            return v;
        }
};


