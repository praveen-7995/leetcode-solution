class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int& degreeSum, int& nodes){
        visited[node] = true;
        nodes++;
        degreeSum +=adj[node].size();
        for(auto  &neighr : adj[node]){
            if(!visited[neighr]){
                dfs(neighr, adj, visited, degreeSum, nodes);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>visited(n, false);
        int completeComponent = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int nodes = 0;
                int degreeSum = 0;
                dfs(i, adj, visited, degreeSum , nodes);
                int edgeNode = degreeSum / 2;
                if(edgeNode == nodes * (nodes - 1) / 2){
                    completeComponent++;
                }
            }
        }
        return completeComponent;

    }
};