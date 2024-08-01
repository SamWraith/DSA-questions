class Solution {
public:
    bool bfs (int start, int colour[], vector<vector<int>>& graph){
        queue<int> q;
        colour[start] = 0;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                // if adj node is not coloured
                if(colour[it] == -1){
                    colour[it] = !colour[node];
                    q.push(it);
                }
                // if it is coloured but same as adj node
                else if(colour[it] == colour[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // bfs
        int v = graph.size();
        int colour[v];
        for(int i = 0; i<v; i++) colour[i] = -1;

        for(int i = 0; i<v; i++){
            if(colour[i] == -1){
                if(bfs(i, colour, graph) == false)
                    return false;
            }
        }
        return true;
    }
};