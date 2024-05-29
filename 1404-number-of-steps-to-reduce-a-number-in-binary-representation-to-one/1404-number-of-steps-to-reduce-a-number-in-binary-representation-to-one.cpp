class Solution {
public:
    int numSteps(string s) {
        /*
        int steps = 0, n = s.size();
        auto check = [&]() -> bool {
            for(int i = 0; i < n-1; i++){
                if(s[i] == '1')
                    return false;
            }
            if(s[n-1] == '1') return true;
            else return true;
        };

        while(!check()){
            if(s[n-1] == '1'){
                int carry = 1;
                for(int i = n-1; i >= 0; i--){
                    if(s[i] == '1' and carry == 1){
                        s[i] = '0';
                    }else{
                        s[i] = '1';
                        carry = 0;
                    }
                }
                if(carry == 1){
                    s = '0' + s;
                    carry = 0;
                    n = s.size();
                }
            }else{
                for(int i = n-1; i >= 0; i--){
                    if(i > 0) s[i] = s[i-1];
                    else s[i] = '0';
                }
            }
            steps++;
            // cout << s << "\n";
        }

        return steps;
        */

        /*
        int steps = 0, i = s.size()-1, carry = 0;
        while(i > 0){
            if(s[i]-'0' + carry == 0){
                // even number with carry = 0 results in even therefore only divide by 2 take 1 step
                carry = 0;
                steps++; 
            }else if(s[i] - '0' + carry == 2){
                // odd number with carry = 1 results in even therefore only divide by 2 take 1 step
                steps++;
            }else{
                // odd number with carry = 0, results in odd number therefore +1 && divide/2, will take two steps
                // even number with carry = 1, results in odd number therefore +1 && divide/2, will take two steps
                carry = 1;
                steps += 2;
            }
            i--;
        }
        if(carry == 1) steps++;
        return steps;
        */
        int i = s.size()-1;
        int steps = i, carry = 0;
        for(i; i > 0; i--){
            if(s[i] - '0' + carry == 1){
                steps++;
                carry = 1;
            }
        }
        return steps+carry;
    }
};