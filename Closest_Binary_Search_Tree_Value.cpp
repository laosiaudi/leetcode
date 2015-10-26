/*********************************************************************************
*     File Name           :     Closest_Binary_Search_Tree_Value.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-25 14:56]
*     Last Modified       :     [2015-10-25 23:26]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        int closestValue(TrieNode* root, double target) {
            double minValue = root->val;
            if (target < root->val)
                recursiveFind(root->left, target, minValue);
            else if (target > root->val)
                recursiveFind(root->right, target, minValue);
            return minValue;
        }

        void recursiveFind(TrieNode* root, double target, double &minValue) {
            if (root == NULL)
                return;
            double tmp = fabs(target, root->val);
            if (tmp < 0.0000001) {
                minValue = root->val;
                return;
            }
            if (tmp < fabs(target, minValue))
                minValue = root->val;
            if (target < root->val)
                recursiveFind(root->left, target, minValue);
            else if (target > root->val)
                recursiveFind(root->right, target, minValue);
        }
};


