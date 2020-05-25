#include <stdlib.h>
#include <unordered_map>
using namespace std;
// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
// 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

struct DLinkNode {
    int key;
    int value;
    DLinkNode* pre;
    DLinkNode* next;
    DLinkNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, DLinkNode*> hash;
    DLinkNode* head, *tail;
    int capacity, size;
public:
    void addToHead(DLinkNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }
    void removeNode(DLinkNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void moveToHead(DLinkNode* node) {
        removeNode(node);
        addToHead(node);
    }
    DLinkNode* removeTail() {
        DLinkNode* node = tail->pre;
        removeNode(node);
        return node;
    }
    LRUCache(int capacity): size(0) {
        this->capacity = capacity;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (hash.count(key) <= 0) return -1;
        DLinkNode* node = hash[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (hash.count(key) <= 0) {
            DLinkNode* newNode = new DLinkNode(key, value);
            hash[key] = newNode;
            addToHead(newNode);
            ++size;
            if (size > capacity) {
                DLinkNode* removed = removeTail();
                hash.erase(removed->key);
                --size;
            }
        } else {
            DLinkNode* node = hash[key];
            node->value = value;
            moveToHead(node);
        }
    }
};