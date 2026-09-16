class Solution {
public:
bool dfs(int node,int destination,vector<vector<int>>& adj,vector<int>& vis){
    if(node == destination)
    return true;
    
    vis[node] = 1;

    for(int next : adj[node]){
        if(!vis[next]){
            if(dfs(next,destination,adj,vis))
            return true;
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        return dfs(source,destination,adj,vis);
    }
};