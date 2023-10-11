//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 100000000);
        dist[S] = 0;
        V--;
        while(V--){
            for(auto edge: edges){
                int src = edge[0], des = edge[1], wei = edge[2];
                if(wei != INT_MAX && dist[des] > wei+dist[src]){
                    dist[des] = dist[src]+wei;
                }
            }
        }
        
        // check for negative edge
        for(auto edge: edges){
            int src = edge[0], des = edge[1], wei = edge[2];
            if(wei != INT_MAX && dist[des] > wei+dist[src]){
                return {-1};
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends