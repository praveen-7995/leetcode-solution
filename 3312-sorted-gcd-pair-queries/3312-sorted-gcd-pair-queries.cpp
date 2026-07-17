class Solution {
public:
    vector<int> gcdValues(vector<int>& nums,
                          vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int mult = g; mult <= mx; mult += g)
                cnt[g] += freq[mult];
        }

        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            exact[g] = cnt[g] * (cnt[g] - 1) / 2;

            for (int mult = 2 * g;
                 mult <= mx;
                 mult += g) {

                exact[g] -= exact[mult];
            }
        }

        vector<long long> prefix(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            prefix[g] = prefix[g - 1] + exact[g];
        }

        vector<int> ans;

        for (long long q : queries) {

            int g = lower_bound(
                        prefix.begin(),
                        prefix.end(),
                        q + 1
                    ) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};