//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &arr) {
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;
        int mod = 1e9+7;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            while(!st.empty() && st.top().first > arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            left[i] = cnt;
            st.push({arr[i], cnt});
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            int cnt = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            right[i] = cnt;
            st.push({arr[i], cnt});
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) ans += (arr[i]%mod * left[i]%mod * right[i]%mod)%mod;
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends