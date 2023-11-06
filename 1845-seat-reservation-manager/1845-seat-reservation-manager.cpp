class SeatManager {
    int num = 1;
    priority_queue<int, vector<int>, greater<>> min_heap;
public:
    SeatManager(int limit) {}
    
    int reserve() {
        if(min_heap.empty()) return num++;
        int d = min_heap.top();
        min_heap.pop();
        return d;
    }
    
    void unreserve(int s) {
        min_heap.push(s);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */