class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            if(leftChild[i] != -1){
                indegree[leftChild[i]]++;
            }
            if(rightChild[i] != -1){
                indegree[rightChild[i]]++;
            }
        }
        int root = -1;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                if(root != -1)
                return false;

                root = i;
            }
            else if(indegree[i] > 1){
                return false;
            }
        }

        if(root == -1)
        return false;

        vector<int>visited(n,0);
        queue<int>q;

        q.push(root);
        visited[root]=1;

        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            count ++;

            if(leftChild[node] != -1){
                if(visited[leftChild[node]])
                return false;

                visited[leftChild[node]] = 1;
                q.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                if (visited[rightChild[node]])
                    return false;

                visited[rightChild[node]] = 1;
                q.push(rightChild[node]);
            }
        }
        return count == n;
        
    }
};