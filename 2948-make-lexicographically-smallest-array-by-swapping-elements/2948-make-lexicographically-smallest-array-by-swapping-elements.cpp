class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int i = 0;

        while(i < n) {

            int j = i;

            // Find all elements that can be connected
            while(j + 1 < n &&
                  v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Get their original positions
            vector<int> pos;

            for(int k = i; k <= j; k++) {
                pos.push_back(v[k].second);
            }

            sort(pos.begin(), pos.end());

            // Put smallest values at smallest positions
            for(int k = 0; k < pos.size(); k++) {
                nums[pos[k]] = v[i + k].first;
            }

            i = j + 1;
        }

        return nums;
    }
};