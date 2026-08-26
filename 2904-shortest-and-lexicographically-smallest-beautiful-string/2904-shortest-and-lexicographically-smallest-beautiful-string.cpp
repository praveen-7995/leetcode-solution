class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        int min_len = INT_MAX;
        string result = "";
        int left = 0;
        int CountOne = 0;
        for(int right = 0; right < n; right++){
            if(s[right] == '1'){
                CountOne++;
            }
            while(CountOne == k){
                int currentLen = right - left + 1;
                string subLen = s.substr(left, currentLen);
                if(currentLen < min_len){
                    min_len = currentLen;
                    result = subLen;
                }else if(currentLen == min_len){
                    if(result == "" || subLen < result){
                        result = subLen;
                    }
                }
                if(s[left] == '1'){
                    CountOne--;
                }
                left++;
            }
        }
        return result;
    }
};