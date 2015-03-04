/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
struct node{
    int key;
    int value;
    node* prev;
    node* next;
    node(int k, int v):key(k), value(v), prev(NULL), next(NULL){};
};

class LRUCache{
public:
    LRUCache(int capacity) {
        if(capacity < 0)
            return;
        cap = capacity;
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        map<int, node*>::iterator it = mapping.find(key);
        if(it != mapping.end())
        {
            node* p = it->second;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            putAtHead(p);
            return p->value;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        if(cap < 1)
            return;
        map<int, node*>::iterator it = mapping.find(key);
        if(it != mapping.end())
        {
            node* p = it->second;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            putAtHead(p);
            p->value = value;
        }
        else
        {
            if(mapping.size() >= cap)
            {//erase the last one
                it = mapping.find(tail->prev->key);
                node* p = it->second;
                
                p->prev->next = p->next;
                p->next->prev = p->prev;
                
                delete p;
                mapping.erase(it);
            }
           //insert at head
           node* p = new node(key, value);
           putAtHead(p);
           mapping[key] = p;
        }
    }
    
    void putAtHead(node* p)
    {
         p->next = head->next;
         head->next->prev = p;
         p->prev = head;
         head->next = p;
    }
    
private:
    int cap;
    map<int, node* > mapping;
    node* head;
    node* tail;
};
