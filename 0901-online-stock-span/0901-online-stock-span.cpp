class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
        s.push(make_pair(1e5+10,0));
    }
    
    int next(int price) {
       int i=s.top().second + 1;
       while(s.top().first<=price){
           s.pop();
       } 
       int ans=i-s.top().second;
       s.push(make_pair(price,i));
       return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */