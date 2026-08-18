class Solution {
public:
bool dfs(int node,int color,vector<vector<int>>& adj,vector<int>& colors){
    colors[node]=color;
    for(int neighbour : adj[node]){
        if(colors[neighbour] == -1){
            if (!dfs(neighbour, 1 - color, adj, colors))
            return false;
        }
        else if(colors[neighbour]==colors[node]){
            return false;
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);

        for(auto edge : dislikes){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>colors(n+1,-1);
        for(int i=1;i<=n;i++){
            if(colors[i]==-1){
                if(!dfs(i,0,adj,colors))
                return false;
            }
        }
        return true;
    }
};