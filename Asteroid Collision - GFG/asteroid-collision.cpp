//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &ast) {
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends