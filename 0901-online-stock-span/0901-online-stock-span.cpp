class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        stack<int> st;
        int ans = 1;
        for(int i = prices.size()-2; i >= 0; i--){
            if(prices[i] <= price) ans++;
            else break;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */