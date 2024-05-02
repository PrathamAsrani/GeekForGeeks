typedef long long ll;

class Solution {
public:
    int X;
    bool check(vector<bool> &curr, vector<bool> &v){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(curr[i] == true && v[i] == true) ans += (1 << i);
        }
        return ans == X;
    }
    long long minEnd(int n, int x) {
        /*
        vector<ll> ans;
        ans.push_back(x);
        X = x;
        vector<bool> v(32, 0);
        for(int i = 0; i < 32; i++){
            if(x & (1 << i)){
                v[i] = true;
            }
        }
        for(int i = 1; i < n; i++){
            int x = ans.back();
            while(true){
                x++;
                vector<bool> curr(32, 0);
                for(int j = 0; j < 32; j++){
                    if(x & (1 << j)){
                        curr[j] = true;
                    }
                }
                if(check(curr, v)){
                    cout << x << "\n";
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans.back();
        */

        ll a = x;
        while(--n)
            a = (a+1) | x;
        return a;
    }
};