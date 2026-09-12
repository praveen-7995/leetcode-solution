#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;

        Node(long long s = LLONG_MIN, vector<int> v = {})
            : score(s), ids(v) {}
    };

    // Return true if a is better than b
    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return lexicographical_compare(
            a.ids.begin(), a.ids.end(),
            b.ids.begin(), b.ids.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, original_index}
        vector<array<long long, 4>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a[1] != b[1])
                return a[1] < b[1];

            return a[0] < b[0];
        });

        // Store all right endpoints
        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = v[i][1];

        /*
            dp[k][i] =
            best answer using at most k intervals
            among first i sorted intervals.

            i ranges from 0 to n.
            k ranges from 0 to 4.
        */
        vector<vector<Node>> dp(
            5, vector<Node>(n + 1, Node(LLONG_MIN))
        );

        // Choosing nothing has score 0
        for (int k = 0; k <= 4; k++)
            for (int i = 0; i <= n; i++)
                dp[k][i] = Node(0, {});

        for (int k = 1; k <= 4; k++) {

            for (int i = 1; i <= n; i++) {

                // Option 1: don't take current interval
                dp[k][i] = dp[k][i - 1];

                long long l = v[i - 1][0];
                long long w = v[i - 1][2];
                int originalIndex = v[i - 1][3];

                /*
                    Find number of previous intervals whose
                    right endpoint is STRICTLY smaller than l.

                    This is important because:
                    [1,3] and [3,5] overlap.
                    
                    Therefore we need:
                    previous_r < current_l
                */
                int p = lower_bound(
                    ends.begin(),
                    ends.begin() + (i - 1),
                    l
                ) - ends.begin();

                // Option 2: take current interval
                Node take = dp[k - 1][p];

                take.score += w;
                take.ids.push_back(originalIndex);

                // The required answer must be sorted by index
                sort(take.ids.begin(), take.ids.end());

                // Choose maximum score,
                // and lexicographically smallest indices on tie
                if (better(take, dp[k][i]))
                    dp[k][i] = take;
            }
        }

        return dp[4][n].ids;
    }
};