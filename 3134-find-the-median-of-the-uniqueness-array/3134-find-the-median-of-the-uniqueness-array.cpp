typedef long long ll;

class Solution {
public:
    ll helper(vector<ll> & arr){
        unordered_map<ll, bool> umpp;
        for(auto x: arr) umpp[x] = true;
        return umpp.size();
    }

    ll helper(vector<int>& nums, ll k){
        ll n = nums.size(), ans = 0;
        ll i = 0, j = 0;
        unordered_map<ll, ll> umpp;
        while(j < n){
            umpp[nums[j]]++;
            while(umpp.size() > k){
                umpp[nums[i]]--;
                if(umpp[nums[i]] == 0) umpp.erase(nums[i]);
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }

    ll medianOfUniquenessArray(vector<int>& nums) {
        /*
        // brute force
        ll n = nums.size();
        multiset<ll> mset;
        for(ll i = 0; i < n; i++){
            for(ll j = i; j < n; j++){
                vector<ll> sub;
                for(ll k = i; k <= j; k++){
                    sub.push_back(nums[k]);
                }
                mset.insert(helper(sub));
            }
        }
        auto itr = mset.begin();
        advance(itr, ceil(mset.size()/2.0)-1);
        return *itr;
        */
        
        ll n = nums.size();
        ll total = n * (n+1)/2;
        ll left = 1, right = unordered_set<ll>(nums.begin(), nums.end()).size();
        while(left < right){
            ll mid = (left+right)/2;
            if(helper(nums, mid) * 2 >= total)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};