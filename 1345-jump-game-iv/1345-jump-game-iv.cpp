class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int idx = q.front();
                q.pop();

                if(idx == n - 1) return steps;
                if(idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = true;
                    q.push(idx - 1);
                }
                if(idx + 1 < n && !visited[idx + 1]) {
                    visited[idx + 1] = true;
                    q.push(idx + 1);
                }
                for(int next : mpp[arr[idx]]) {
                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                mpp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};