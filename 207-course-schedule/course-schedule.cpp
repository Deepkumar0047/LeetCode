class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, 
             vector<int>& visited, vector<int>& path) {
        
        visited[node] = 1;
        path[node] = 1;

        for (int next : adj[node]) {
            
            if (path[next] == 1)
                return false;

            if (visited[next] == 0) {
                if (!dfs(next, adj, visited, path))
                    return false;
            }
        }

        path[node] = 0;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for (auto p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, path))
                    return false;
            }
        }

        return true;
    }
};