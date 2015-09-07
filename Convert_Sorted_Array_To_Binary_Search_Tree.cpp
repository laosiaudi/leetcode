/*********************************************************************************
*     File Name           :     Convert_Sorted_Array_To_Binary_Search_Tree.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-07 13:22]
*     Last Modified       :     [2015-09-07 13:36]
*     Description         :
**********************************************************************************/

/**
 * Definition for a binary tree node.
 *  struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 * */
class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            int n = nums.size();
            if (n == 0)
                return NULL;
            int mid = (n - 1)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            if (0 <= mid - 1)
                root->left = constructSubTree(0, mid - 1, nums);
            if (mid + 1 <= n - 1)
                root->right = constructSubTree(mid + 1, n - 1, nums);
            return root;
        }

        TreeNode* constructSubTree(int start, int end, vector<int>& nums) {
            int index = (start + end)/2;
            int rootVal = nums[index];
            TreeNode* root = new TreeNode(rootVal);
            if (start <= index - 1)
                root->left = constructSubTree(start, index - 1, nums);
            if (index + 1 <= end)
                root->right = constructSubTree(index + 1, end, nums);
            return root;
        }
};


