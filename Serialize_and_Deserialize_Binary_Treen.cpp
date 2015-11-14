class Codec {
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string result;
            recursiveSerial(root,result);
            return result;
        }
        void recursiveSerial(TreeNode* root, string &result) {
            if (root == NULL) {
                result = result + "#";
                return;
            }

            result = result + to_string(root->val) + ",";
            string left = serialize(root->left);
            string right = serialize(root->right);
            result = result + left + right;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            int index = 0;
            return recursiveDeserialize(data, index);
        }

        TreeNode* recursiveDeserialize(string &data, int &index) {
            if (index >= data.size() || data[index] == '#')
                return NULL;
            int end = index;
            while (data[end] != ',')
                end ++;
            TreeNode* root = new TreeNode(atoi(data.substr(index, end - index).c_str()));
            index = end + 1;
            root->left = recursiveDeserialize(data, index);
            index = index + 1;
            root->right = recursiveDeserialize(data, index);
            return root;
        }
};
