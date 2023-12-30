class LRUCache {
public:
//     unordered_map<int, int> umpp;
//     unordered_map<int, list<int>::iterator> addr;
//     list<int> l;
//     int cap, size;
//     LRUCache(int cap) {
//         size = 0;
//         this->cap = cap;
//     }
    
//     int get(int key) {
//         if(umpp.find(key) == umpp.end()) return -1;
//         list<int>::iterator it = addr[key];
//         l.erase(it);
//         addr.erase(key);
//         l.push_front(key);
//         addr[key]=l.begin();
//         return umpp[key];
//     }
    
//     void put(int key, int value) {
//         if(umpp.find(key) != umpp.end()){
//             l.erase(addr[key]);
//             addr.erase(key);
//             umpp.erase(key);
//             size--;
//         }
//         if(size >= cap){
//             int delKey = l.back();
//             l.pop_back();
//             addr.erase(delKey);
//             umpp.erase(delKey);
//             size--;
//         }
//         size++;
//         l.push_front(key);
//         addr[key] = l.begin();
//         umpp[key] = value;
//     }
    
    public:
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            l.splice(l.begin(), l, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            l.splice(l.begin(), l, mp[key]);
            mp[key]->second = value;
            return;
        }
        if(l.size()==size)
        {
            int dkey = l.back().first;
            l.pop_back();
            mp.erase(dkey);
        }
        l.push_front(make_pair(key, value));
        mp[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */