//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
    {
        // long long int one = 1e9, two = 1e9;
        // unordered_map<long long int, int> umpp;
        // for(int i = 0; i < N; i++) umpp[arr[i]]++;
        // for(auto i:umpp) {
        //     if(i.second%2 == 1) {
        //         if(one == 1e9) one = i.first;
        //         else if(two == 1e9) two = i.first;
        //     }
        // }
        // if(two > one) return {two, one};
        // else return {one, two};
        
        
        long long int all = 0, i;
        for(i = 0; i < N; i++){
            all ^= arr[i];
        }
        
        long long int m = all & -all, g1 = 0, g2 = 0;
        
        for(i = 0; i < N; i++){
            if((m&arr[i]) == 0) g1 ^= arr[i];
            else g2 ^= arr[i];
        }
        if(g1 > g2) return {g1, g2};
        else return {g2, g1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends