//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    long long modInverse(long long a, int m){
        return modPower(a, m-2, m);
    }
    long long modPower(long long base, int expo, int mod){
        long long result = 1;
        while(expo > 0){
            if(expo%2 == 1) result = (result*base)%mod;
            base = (base*base)%mod;
            expo /= 2;
        }
        return result;
    }
    public:
    long long numberOfPaths(int M, int N)
    {
        int n = M+N-2, r = M-1, mod = 1e9+7;
        long long ans = 1;
        
        for(int i = 0; i < r; i++){
            ans = (ans*(n-i))%mod;
            ans = (ans*(modInverse(i+1, mod)))%mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends