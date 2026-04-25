class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> st;
        int n = nums.size();
        int total = (1 << n);

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            st.insert(subset);
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};