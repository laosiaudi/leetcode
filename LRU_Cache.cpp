/*********************************************************************************
*     File Name           :     LRU_Cache.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-18 17:40]
*     Last Modified       :     [2015-10-18 19:41]
*     Description         :
**********************************************************************************/
#include <map>
#include <vector>

using namespace std;
class LRUCache{
    public:
        struct Node {
            int key;
            int value;
            Node* pre;
            Node* next;
            Node(int k, int v) {
                key = k;
                value = v;
                pre = next = NULL;
            }
        };
        Node* head;
        Node* tail;
        int capacity;
        int cnt;
        map<int,Node*>table;
        LRUCache(int capacity) {
           this->capacity = capacity;
           cnt = 0;
           head = new Node(0, 0);
           tail = head;
        }

        int get(int key) {
            if (table.find(key) == std::end(table))
                return -1;
            int v = table[key]->value;
            adjustCache(key);
            return v;
        }

        void set(int key, int value) {
            if (table.find(key) == std::end(table)) {
                if (cnt == capacity) {
                    int old_key = head->next->key;
                    table.erase(old_key);
                    Node* old_node = head->next;
                    head->next = old_node->next;
                    if (old_node->next != NULL)
                        old_node->next->pre = head;
                    Node* new_node = new Node(key, value);
                    if (tail != old_node) {
                        tail->next = new_node;
                        new_node->pre = tail;
                    } else {
                        head->next = new_node;
                        new_node->pre = head;
                    }
                    table[key] = new_node;
                    tail = new_node;
                    delete old_node;
                } else {
                    Node* new_node = new Node(key, value);
                    tail->next = new_node;
                    new_node->pre = tail;
                    tail = new_node;
                    table[key] = new_node;
                    cnt ++;
                }
            } else {
                table[key]->value = value;
                adjustCache(key);
            }
        }

        void adjustCache(int key) {
            if (tail == table[key])
                return;
            Node* pre = table[key]->pre;
            Node* next = table[key]->next;
            pre->next = next;
            next->pre = pre;
            table[key]->next = tail->next;
            table[key]->pre = tail;
            tail->next = table[key];
            tail = table[key];
        }
};


