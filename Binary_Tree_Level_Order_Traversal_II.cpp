/*********************************************************************************
*     File Name           :     Binary_Tree_Level_Order_Traversal.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-06 19:56]
*     Last Modified       :     [2015-09-06 20:20]
*     Description         :
**********************************************************************************/
#include <vector>
#include <queue>
#include <stack>
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            queue<TreeNode*>q;
            stack<int>s;
            stack<int>count;
            vector<vector<int>>v;

            if (root == NULL)
                return v;
            q.push(root);

            while (!q.empty()) {
                int size = q.size();
                vector<int>tmp;
                int cnt = 0;
                for (int i = 0;i < size; i ++) {
                    TreeNode* tmpNode = q.front();
                    if (tmpNode != NULL) {
                        tmp.push_back(tmpNode->val);
                        q.push(tmpNode->left);
                        q.push(tmpNode->right);
                        s.push(tmpNode->val);
                        cnt ++;
                    }
                    q.pop();
                }
                if (cnt > 0)
                    count.push(cnt);
            }

            while (!count.empty()) {
                int cnt = count.top();
                count.pop();
                vector<int>tmp(cnt, 0);
                for (int i = cnt - 1; i >= 0; i --) {
                    tmp[i] = s.top();
                    s.pop();
                }
                v.push_back(tmp);
            }
            return v;
        }
};


