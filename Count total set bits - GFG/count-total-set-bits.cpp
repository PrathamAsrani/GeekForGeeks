//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int cntBits(int n){
    int cnt = 0;
    while(n){
        if(n&1) cnt++;
        n >>= 1;
    }
    return cnt;
}

int max2Power(int n){
    int c = 0;
    while((1 << c) <= n) c++;
    return c-1;
}

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int N)
    {
        /*
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt += cntBits(i);
        return cnt;
        */
        
        if(N == 0) return 0;
        int x = max2Power(N);
        int ans = x*(1 << (x-1)) + (N-(1<<x)) + 1 + countSetBits(N-(1<<x));
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends