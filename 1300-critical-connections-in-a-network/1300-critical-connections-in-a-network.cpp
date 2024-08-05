class Solution {
private:
    int timer = 0;
public:
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, 
    vector<vector<int>> &bridges, int tin[], int low[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto it: adj[node]){
            if( it == parent) continue;
            if(!vis[it]){
                dfs(it, node, adj, vis, bridges, tin, low);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it, node});
                }
            }
            else
                low[node] = min(low[node], low[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        vector<int> vis(n, 0 );
        vector<int> adj[n];
        int tin[n];
        int low[n];
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, adj, vis, bridges, tin, low);

        return bridges;
    }
};