// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-21 20:13:17
// MODIFIED: 2015-04-21 21:40:46
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
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            int number = preorder.size();
            if (number == 0)
                return NULL;

            int root = preorder[0];
            TreeNode* rootNode = new TreeNode(root);
            int rootIndex;
            for (int i = 0; i < number; i ++) {
                if (root == inorder[i]) {
                    rootIndex = i;
                    break;
                }
            }
            TreeNode* leftRootNode;
            TreeNode* rightRootNode;
            if (rootIndex - 1 >= 0) {
                int leftRoot = preorder[1];
                leftRootNode = buildSubTree(preorder, inorder, 0, rootIndex - 1, 1, leftRoot);
            } else {
                leftRootNode = NULL; 
            }
            if (rootIndex + 1<= number - 1) {
                int rightRoot = preorder[rootIndex + 1];
                rightRootNode = buildSubTree(preorder, inorder, rootIndex + 1, number - 1, rootIndex + 1, rightRoot);
            } else {
                rightRootNode = NULL;
            }
            rootNode->left = leftRootNode;
            rootNode->right = rightRootNode;
            return rootNode;
        }

        TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int index, int root) {
            if (start == end) {
                TreeNode* child = new TreeNode(inorder[start]);
                return child;
            }
            TreeNode* rootNode = new TreeNode(root);

            int rootIndex;
            for (int i = start; i <= end; i ++) {
                if (root == inorder[i]) {
                    rootIndex = i;
                    break;
                }
            }
            TreeNode* leftRootNode;
            TreeNode* rightRootNode;
            if (rootIndex  - 1 >= start) {
                int leftRoot = preorder[index + 1];
                leftRootNode = buildSubTree(preorder, inorder, start, rootIndex - 1, index + 1, leftRoot);
            } else {
                leftRootNode = NULL;
            }
            if (rootIndex  + 1 <= end) {
                int rightRoot = preorder[index + rootIndex - start + 1];
                rightRootNode = buildSubTree(preorder, inorder, rootIndex + 1, end, index + rootIndex - start + 1, rightRoot);
            } else {
                rightRootNode = NULL;
            }
            rootNode->left = leftRootNode;
            rootNode->right = rightRootNode;

            return rootNode;
        }
};
