class LRUCache {
public:
    unordered_map<int, int> umpp;
    unordered_map<int, list<int>::iterator> addr;
    list<int> l;
    int cap, size;
    LRUCache(int cap) {
        size = 0;
        this->cap = cap;
    }
    
    int get(int key) {
        if(umpp.find(key) == umpp.end()) return -1;
        list<int>::iterator it = addr[key];
        l.erase(it);
        addr.erase(key);
        l.push_front(key);
        addr[key]=l.begin();
        return umpp[key];
    }
    
    void put(int key, int value) {
        if(umpp.find(key) != umpp.end()){
            l.erase(addr[key]);
            addr.erase(key);
            umpp.erase(key);
            size--;
        }
        if(size >= cap){
            int delKey = l.back();
            l.pop_back();
            addr.erase(delKey);
            umpp.erase(delKey);
            size--;
        }
        size++;
        l.push_front(key);
        addr[key] = l.begin();
        umpp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */