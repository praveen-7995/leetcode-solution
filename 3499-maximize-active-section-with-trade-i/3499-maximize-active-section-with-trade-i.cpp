class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int activeCount = count(s.begin(), s.end(), '1');
        int n = s.size();

        vector<int> inactiveCount;

        int i = 0;

        while (i < n) {

            if (s[i] == '0') {

                int start = i;

                while (i < n && s[i] == '0')
                    i++;

                inactiveCount.push_back(i - start);
            }
            else {
                i++;
            }
        }

        int maxSumPair = 0;

        for (int i = 1; i < inactiveCount.size(); i++) {
            maxSumPair = max(maxSumPair,
                             inactiveCount[i] + inactiveCount[i - 1]);
        }

        return activeCount + maxSumPair;
    }
};