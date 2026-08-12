class Solution {
public:
    int timer = 0;

    void DFS(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& disc,
             vector<int>& low,
             vector<vector<int>>& ans) {

        disc[node] = low[node] = timer++;

        for (int next : adj[node]) {
            if (next == parent)
                continue;

            if (disc[next] != -1) {
                low[node] = min(low[node], disc[next]);
            }
            else {
                DFS(next, node, adj, disc, low, ans);
                low[node] = min(low[node], low[next]);

                if (low[next] > disc[node]) {
                    ans.push_back({node, next});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                DFS(i, -1, adj, disc, low, ans);
            }
        }

        return ans;
    }
};