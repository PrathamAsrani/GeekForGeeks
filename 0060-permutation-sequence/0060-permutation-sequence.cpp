class Solution {
public:
    void fun(vector<int> &arr, int n, int k, int fac, string &ans){
        if(arr.size() == 1){
            ans += to_string(arr[0]);
            return;
        }
        fac = fac/n;
        int idx = k/fac;
        ans += to_string(arr[idx]);
        arr.erase(arr.begin()+idx);
        k = k%fac;
        return fun(arr, arr.size(), k, fac, ans);
    }
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> arr;
        int fac = 1;
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
            fac *= i;
        }
        // fun(arr, arr.size(), k-1, fac, ans);
        
        k--;
        while(!arr.empty()){
            if(arr.size() == 1){
                ans += to_string(arr[0]);
                break;
            }
            fac = fac/arr.size();
            int idx = k/fac;
            ans += to_string(arr[idx]);
            arr.erase(arr.begin()+idx);
            k = k%fac;
        }
        return ans;
    }
};