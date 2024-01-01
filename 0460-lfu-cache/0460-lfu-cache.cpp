class Node{
    public:
    int key, value, cnt;
    Node *next, *prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};

class List{
    public:
    int size;
    Node *head, *tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node){
        Node *tmp = head->next;
        node->next = tmp;
        node->prev = head;
        head->next = node;
        tmp->prev = node;
        size++;
    }

    void removeNode(Node *node){
        Node *ps = node->prev, *ns = node->next;
        ps->next = ns;
        ns->prev = ps;
        size--;
    }
};

class LFUCache {
    public:
    unordered_map<int, Node*> cache;
    unordered_map<int, List*> freqList;
    int maxSizeCache, minFreq, curSize;

    LFUCache(int capacity){
        maxSizeCache = capacity;
        minFreq = 1;
        curSize = 0;
    }

    void updateFreqListMap(Node *node){
        freqList[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqList[node->cnt]->size == 0) 
            minFreq++;
        
        List *nextHigherFreqList;
        if(freqList.find(node->cnt+1) != freqList.end())
            nextHigherFreqList = freqList[node->cnt+1];
        else 
            nextHigherFreqList = new List();
        
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqList[node->cnt] = nextHigherFreqList;
    }

    int get(int key){
        if(cache.find(key) != cache.end()){
            int val = cache[key]->value;
            updateFreqListMap(cache[key]);
            return val;
        }
        return -1;
    }

    void put(int key, int value){
        if(maxSizeCache == 0)
            return ;
        if(cache.find(key) != cache.end()){
            cache[key]->value = value;
            updateFreqListMap(cache[key]);
            return ;
        }
        if(curSize == maxSizeCache){
            // delete last of list with minimun frequency
            List* list = freqList[minFreq];
            int delKey = list->tail->prev->key;
            cache.erase(delKey); 
            list->removeNode(list->tail->prev);
            curSize--;
        }
        curSize++;
        minFreq = 1;
        List* list;
        if(freqList.find(minFreq) != freqList.end())
            list = freqList[minFreq];
        else 
            list = new List();
        
        Node *node = new Node(key, value);
        list->addFront(node);
        cache[key] = node;
        freqList[minFreq] = list;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */