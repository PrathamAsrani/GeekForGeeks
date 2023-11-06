//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<pair<int, int>> st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(st.empty()) return -1;
		    return st.top().second;
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(st.empty()) return -1;
			int d = st.top().first;
			st.pop();
			return d;
       }
       
       /*push element x into the stack*/
       void push(int num){
            if(st.empty()){
				st.push({num, num});
				return ;
			}
			int mn = st.top().second;
			if(num < mn) mn = num;
			st.push({num, mn});
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends