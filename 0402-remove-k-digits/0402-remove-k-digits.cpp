class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> mystack;
        for (char c : num) {
            while (!mystack.empty() && k > 0 && mystack.top() > c){
                mystack.pop();
                k -= 1;
            }
            if (!mystack.empty() || c != '0'){
                mystack.push(c);
            }
        }
        while (!mystack.empty() && k--)
            mystack.pop();
        if (mystack.empty())
            return "0";
        while (!mystack.empty()) {
            num[n - 1] = mystack.top();
            mystack.pop();
            n -= 1;
        }
        return num.substr(n);
    }
};