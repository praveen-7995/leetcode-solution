class Solution {
public:
    bool dfs(vector<int>& arr, int idx){
        int n = arr.size();

        if(idx < 0 || idx >= n || arr[idx] < 0){
            return false;
        }
        if(arr[idx] == 0){
            return true;
        }
        int jump = arr[idx];
        arr[idx] = -1;
        return dfs(arr, idx + jump) || dfs(arr, idx - jump);
    }
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
};