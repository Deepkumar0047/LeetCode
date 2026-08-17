class Solution {
public:
bool dfs(int node,int target,vector<vector<int>>& adj,vector<bool>& visited){
    if(node == target)
    return true;

    visited[node]=true;

    for(int neighbour : adj[node]){
        if(!visited[neighbour]){
            if(dfs(neighbour,target,adj,visited))
            return true;
        }
    }
    return false;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            vector<bool>visited(n+1,false);

            if(dfs(u,v,adj,visited)){
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};