class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n+1];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dis1(n+1, 1e9), dis2(n+1, 1e9);
        queue<pair<int, int>> q;
        q.push({1, 0}); 
        dis1[1] = 0;
        
        while (!q.empty()) {
            int node = q.front().first, curr = q.front().second; q.pop();
            int waiting = ((curr / change) % 2) == 1 ? (change - (curr % change)) : 0;
            int nei_time = curr + waiting + time;
            
            for (auto &nei : adj[node]) {
                if(nei_time < dis1[nei]){
                    dis2[nei] = dis1[nei];
                    dis1[nei] = nei_time;
                    q.push({nei, nei_time});
                } else if (nei_time > dis1[nei] && nei_time < dis2[nei]){
                    dis2[nei] = nei_time;
                    q.push({nei, nei_time});
                }
            }
        }
        
        return dis2[n] == 1e9 ? -1 : dis2[n];
    }
};
