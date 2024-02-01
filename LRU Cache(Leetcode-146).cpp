##C++ code
class LRUCache {
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    void addToHead(Node* node)
    {
        node->next=head->next;
        node->prev=head;
         
        head->next->prev=node;
         head->next=node;

    }

    Node* popTail()
    {
        Node* lastnode=tail->prev;
        remove(lastnode);
        return lastnode;
    }

    void moveToHead(Node* node)
    {
        remove(node);
        addToHead(node);
    }

    void remove(Node*node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;

    }
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;
    LRUCache(int capacity) {
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    
    int get(int key) {
        auto i=cache.find(key);// iterator  The find function returns an iterator pointing to the element if it's found, or cache_.end() if the key is not present.
// if (it != cache_.end()) {
// 
// This checks if the key was found in the cache. If it was found 

        if(i!=cache.end())
        {
            moveToHead(i->second);
            return i->second->value;
        }

        else
        return -1;

    }
    
    void put(int key, int value) {
          auto it=cache.find(key);

        if (it != cache.end()) {
            // If the key already exists, update the value and move it to the front
            it->second->value = value;
            moveToHead(it->second);
        } else {
            // Check if the cache is full
            if (cache.size() == cap) {
                // Remove the least recently used item from both the list and the map
                Node* lastNode = popTail();
                cache.erase(lastNode->key);
                delete lastNode;
            }
            
            // Insert the new key-value pair into the cache and the front of the list
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
