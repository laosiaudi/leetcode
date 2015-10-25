/*********************************************************************************
*     File Name           :     Implement_Trie.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-25 14:33]
*     Last Modified       :     [2015-10-25 15:42]
*     Description         :
**********************************************************************************/

class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode() {
            val = ' ';
            word = false;
        }
        char val;
        bool word;
        unordered_map<char, TrieNode*>children;
};

class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string word) {
            int index = 0;
            TrieNode* tmp = root;
            while (index < word.size()) {
               if (tmp->children.find(word[index]) == std::end(tmp->children)) {
                   TrieNode* newNode = new TrieNode();
                   newNode->val = word[index];
                   index ++;
                   tmp->children[newNode->val] = newNode;
                   tmp = newNode;
               } else {
                   tmp = tmp->children[word[index]];
                   index ++;
               }
            }
            tmp->word = true;
        }

        // Returns if the word is in the trie.
        bool search(string word) {
            TrieNode* tmp = root;
            int index = 0;
            while (index < word.size()) {
                if (tmp->children.find(word[index]) == std::end(tmp->children))
                    return false;
                else {
                    tmp = tmp->children[word[index]];
                    index ++;
                }
            }
            return tmp->word;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            TrieNode* tmp = root;
            int index = 0;
            while (index < prefix.size()) {
                if (tmp->children.find(prefix[index]) == std::end(tmp->children))
                    return false;
                else {
                    tmp = tmp->children[prefix[index]];
                    index ++;
                }
            }
            return true;
        }
    private:
        TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


