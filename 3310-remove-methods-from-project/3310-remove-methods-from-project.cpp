class Solution {
public:
    unordered_set<int>suspicious;
    void dfs(int node, vector<int>&visited, vector<vector<int>>&graph){
        suspicious.insert(node);
        visited[node] = 1;
        for(auto &neighbor : graph[node]){
            if(!visited[neighbor]){
                dfs(neighbor, visited, graph);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>>graph(n);
        vector<unordered_set<int>>invoked_in(n);

        for(const auto& invocation : invocations){
            int u = invocation[0];
            int v = invocation[1];
            graph[u].push_back(v);
            invoked_in[v].insert(u);
        }

        vector<int>visited(n, 0);
        dfs(k, visited, graph);
        bool canremove = true;
        for(auto& method : suspicious){
            for(auto& invoke : invoked_in[method]){
                if(suspicious.find(invoke) == suspicious.end()){
                    canremove = false;
                    break;
                }
            }
            if(!canremove) break;

        }
        vector<int>result;
        if(canremove){
            for(int i = 0; i < n; i++){
                if(suspicious.find(i) == suspicious.end()){
                    result.push_back(i);
                }
            }
        }
        else {
            for(int i = 0; i < n; i++){
                result.push_back(i);
            }
        }
        return result;

    }
};