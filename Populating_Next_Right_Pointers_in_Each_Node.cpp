/*********************************************************************************
*     File Name           :     Populating_Next_Right_Pointers_in_Each_Node.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-10 15:35]
*     Last Modified       :     [2015-09-10 16:13]
*     Description         :
**********************************************************************************/

/**
 *      Definition for binary tree with next pointer.
 *       struct TreeLinkNode {
 *         int val;
 *         TreeLinkNode *left, *right, *next;
 *         TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 *     };
 *      */
class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if (root == NULL)
                return;
            if (root->left != NULL && root->right != NULL) {
                root->left->next = root->right;
                connectTwoNodes(root->left, root->right);
            }
            return;
        }

        void connectTwoNodes(TreeLinkNode* left, TreeLinkNode* right) {
            if (left->left != NULL && right->left != NULL) {
                left->left->next = left->right;
                right->left->next = right->right;
                left->right->next = right->left;
                connectTwoNodes(left->left, left->right);
                connectTwoNodes(left->right, right->left);
                connectTwoNodes(right->left, right->right);
                return;
            }
        }

        //another solution
        //reference:http://siddontang.gitbooks.io/leetcode-solution/content/tree/populating_next_right_pointers_in_each_node.html
        void connect(TreeLinkNode *root) {
            if(!root) {
                return;
            }

            TreeLinkNode* p = root;
            TreeLinkNode* first = NULL;
            while(p) {
                //记录下层第一个左子树
                if(!first) {
                    first = p->left;
                }
                //如果有左子树，那么next就是父节点
                if(p->left) {
                    p->left->next = p->right;
                } else {
                    //叶子节点了，遍历结束
                    break;
                }

                //如果有next，那么设置右子树的next
                if(p->next) {
                    p->right->next = p->next->left;
                    p = p->next;
                    continue;
                } else {
                    //转到下一层
                    p = first;
                    first = NULL;
                }
            }
    }


};


