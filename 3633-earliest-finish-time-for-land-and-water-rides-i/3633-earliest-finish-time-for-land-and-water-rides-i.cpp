class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int minLandEnd = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minLandEnd = min(minLandEnd,
                             landStartTime[i] + landDuration[i]);
        }

        int ans = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            ans = min(ans,
                      max(minLandEnd, waterStartTime[j]) +
                      waterDuration[j]);
        }

        int minWaterEnd = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            minWaterEnd = min(minWaterEnd,
                              waterStartTime[j] + waterDuration[j]);
        }
        for (int i = 0; i < landStartTime.size(); i++) {
            ans = min(ans,
                      max(minWaterEnd, landStartTime[i]) +
                      landDuration[i]);
        }

        return ans;
    }
};