typedef long long ll;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        for(ll a = 1; a*a <= c; a++){
            ll b = c-a*a;
            double d = sqrt(b);
            b = (ll) d;
            if(b == d) 
                return true;
        }
        return false;
    }
};