class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for(auto a:ast){
            while(!st.empty() && st.top() > 0 && a < 0){
                int sum = a+st.top();
                if(sum == 0){
                    a = 0;
                    st.pop();
                }else if(sum < 0){
                    st.pop();
                }else a = 0;
            }
            if(a != 0) st.push(a);
        }
        int n = st.size();
        vector<int> ans(n);
        while(n){
            ans[--n] = st.top();
            st.pop();
        }
        return ans;
    }
};