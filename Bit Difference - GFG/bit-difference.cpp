//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        string _a(32, '0'), _b(32, '0');
        int i = 0;
        while(a){
            if(a&1) _a[i] = '1';
            i++;
            a>>=1;
        }
        i = 0;
        while(b){
            if(b&1) _b[i] = '1';
            i++;
            b>>=1;
        }
        int cnt = 0;
        for(i = 0; i < 32; i++) if(_a[i] != _b[i]) cnt++;
        return cnt;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}
// } Driver Code Ends