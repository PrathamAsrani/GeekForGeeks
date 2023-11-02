//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int m = 1e9+7;
    //You need to complete this fucntion
    long long power(int _N,int R)
    {
        long long ans = 1; 
        long long N = _N%m;
        while(R > 0){
            if(R%2 == 1){
                ans = (ans*N)%m;
                R--;
            }else{
                N = (N*N)%m;
                R >>= 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends