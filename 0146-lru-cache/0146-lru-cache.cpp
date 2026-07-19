#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    void addnode(Node* newnode) {
        Node* oldnext = head->next;

        head->next = newnode;
        newnode->prev = head;

        newnode->next = oldnext;
        oldnext->prev = newnode;
    }

    void delnode(Node* oldnode) {
        Node* oldprev = oldnode->prev;
        Node* oldnext = oldnode->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) { // does not exxit
            return -1;
        }

        Node* ansnode = m[key];
        int ans = ansnode->val;

        delnode(ansnode);
        addnode(ansnode);

        return ans;
    }

    void put(int key, int value) {

        if (m.find(key) != m.end()) {
            Node* oldnode = m[key];

            delnode(oldnode);
            m.erase(key);
            delete oldnode;
        }

        // capacity reached
        if (m.size() == limit) {
            Node* lru = tail->prev;

            delnode(lru);
            m.erase(lru->key);
            delete lru;
        }

        // insert new node
        Node* newnode = new Node(key, value);
        addnode(newnode);
        m[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */