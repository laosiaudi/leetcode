// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-21 20:13:17
// MODIFIED: 2015-04-21 22:02:38
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
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            int number = inorder.size();
            if (number == 0)
                return NULL;

            int root = postorder[number - 1];
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
                int leftRoot = postorder[number - 1 - (number - 1 - rootIndex) - 1];
                leftRootNode = buildSubTree(inorder, postorder, 0, rootIndex - 1, rootIndex - 1, leftRoot);
            } else {
                leftRootNode = NULL;
            }
            if (rootIndex + 1<= number - 1) {
                int rightRoot = postorder[number - 1 - 1];
                rightRootNode = buildSubTree(inorder, postorder, rootIndex + 1, number - 1, number - 1 - 1, rightRoot);
            } else {
                rightRootNode = NULL;
            }
            rootNode->left = leftRootNode;
            rootNode->right = rightRootNode;
            return rootNode;
        }

        TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder, int start, int end, int index, int root) {
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
                int leftRoot = postorder[index - (end - rootIndex) - 1];
                leftRootNode = buildSubTree(inorder, postorder, start, rootIndex - 1, index - (end - rootIndex) - 1, leftRoot);
            } else {
                leftRootNode = NULL;
            }
            if (rootIndex  + 1 <= end) {
                int rightRoot = postorder[index - 1];
                rightRootNode = buildSubTree(inorder, postorder, rootIndex + 1, end, index - 1, rightRoot);
            } else {
                rightRootNode = NULL;
            }
            rootNode->left = leftRootNode;
            rootNode->right = rightRootNode;

            return rootNode;
        }
};
