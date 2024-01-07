typedef long long ll;

class Solution {
public:
    pair<ll, ll> findLowHigh(vector<int> &arr, int n){
        ll low = arr[0], high = arr[0];
        for(int i = 1; i < n; i++){
            if(low < arr[i])
                low = arr[i];
            high += arr[i];
        }
        return {low, high};
    }
    
    ll findDays_Capacity(vector<int> &arr, int n, ll capacity){
        ll days = 1, load = arr[0];
        for(int i = 1; i < n; i++){
            if((load + arr[i]) <= capacity)
                load += arr[i];
            else{
                days++;
                load = arr[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(days > n) 
            return -1;
        pair<ll ,ll> p = findLowHigh(weights, n);
        ll low = p.first, high = p.second;
        while(low <= high){
            ll mid_capa = low+(high-low)/2;
            if(findDays_Capacity(weights, n, mid_capa) <= days)
                high = mid_capa-1;
            else
                low = mid_capa+1;
        }
        return low;
    }
};