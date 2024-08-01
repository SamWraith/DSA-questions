class Solution {
public:
    bool dfs(int node, int col, int colour[], vector<vector<int>>& graph){
        colour[node] = col;
        for(auto it: graph[node]){
            // it adj node is not coloured
            if(colour[it] == -1){
                if(dfs(it, !col, colour, graph) == false)
                    return false;
            }
            // it is coloured but same as adj node
            else if(colour[it] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // dfs
        int v = graph.size();
        int colour[v];
        for(int i = 0; i<v; i++) colour[i] = -1;

        for(int i = 0; i<v; i++){
            if(colour[i] == -1){
                if(dfs(i, 0, colour, graph) == false)
                    return false;
            }
        }
        return true;
    }
};