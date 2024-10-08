class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int indegree[v];
        for(int i = 0; i<v; i++)
            indegree[i] = 0;
        
        vector<int> adj[v];
        queue<int> q;
        vector<int> topo;
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i<v; i++ ){
            for( auto it: adj[i])
                indegree[it]++;
        }
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == v) return true;
        return false;
    }
};