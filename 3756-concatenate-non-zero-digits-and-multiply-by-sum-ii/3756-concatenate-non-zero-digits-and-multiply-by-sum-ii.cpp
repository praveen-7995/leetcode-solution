class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> cnt(n + 1, 0);
        vector<long long> digitSum(n + 1, 0);
        vector<long long> pref(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            cnt[i + 1] = cnt[i];
            digitSum[i + 1] = digitSum[i] + d;
            pref[i + 1] = pref[i];

            if (d != 0) {
                cnt[i + 1]++;
                pref[i + 1] = (pref[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long k = cnt[r + 1] - cnt[l];
            long long sum = digitSum[r + 1] - digitSum[l];

            long long x =
                (pref[r + 1] - pref[l] * pow10[k] % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};