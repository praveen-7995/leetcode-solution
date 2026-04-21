class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) parent[px] = py;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int ans = 0;
        for (auto &g : groups) {
            unordered_map<int, int> freq;
            for (int idx : g.second) {
                freq[source[idx]]++;
            }
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};