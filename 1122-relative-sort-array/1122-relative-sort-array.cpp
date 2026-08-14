class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();
        unordered_map<int, int>mp;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            mp[arr1[i]]++;
        }
        for(int i = 0; i < m; i++){
            int element = arr2[i];
            while(mp[element] > 0){
                ans.push_back(element);
                mp[element]--;
            }
        }
        vector<int>remaning;
        for(auto it : mp){
            while(it.second > 0){
                remaning.push_back(it.first);
                it.second--;
            }
        }
        sort(remaning.begin(), remaning.end());
        for(int i = 0; i < remaning.size(); i++){
            ans.push_back(remaning[i]);
        }
        return ans;
    }
};