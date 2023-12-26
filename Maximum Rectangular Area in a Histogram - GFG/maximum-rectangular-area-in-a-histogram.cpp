//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long

class Solution
{
    public:
    vector<ll> prevSmaller(long long arr[], int n){
      stack<ll> st;
      vector<ll> ps(n);
      for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(st.empty()) ps[i] = -1;
        else ps[i] = st.top();
        st.push(i);
      }
      return ps;
    }
    
    
    vector<ll> nextSmaller(long long arr[], int n){
      stack<ll> st;
      vector<ll> ns(n);
      for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(st.empty()) ns[i] = n;
        else ns[i] = st.top();
        st.push(i);
      }
      return ns;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<ll> ps = prevSmaller(arr, n), ns = nextSmaller(arr, n);
        ll maxAns = 0;
        for(int i = 0; i < n; i++){
          ll curr = (ns[i] - ps[i] - 1) * arr[i];
          maxAns = max(maxAns, curr);
        }
        return maxAns;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends