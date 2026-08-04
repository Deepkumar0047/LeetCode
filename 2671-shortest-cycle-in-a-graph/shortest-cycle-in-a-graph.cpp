class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans=INT_MAX;
        for(int start =0;start<n;start++)
        {
            vector<int>dist(n,-1);
            vector<int>parent(n,-1);

            queue<int>q;

            dist[start]=0;
            q.push(start);

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int adjNode : adj[node]){
                    if(dist[adjNode]==-1){
                        dist[adjNode]=dist[node]+1;
                        parent[adjNode]=node;
                        q.push(adjNode);
                    }
                    else if(parent[node] != adjNode){
                        ans=min(ans,dist[node] + dist[adjNode]+1);
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};