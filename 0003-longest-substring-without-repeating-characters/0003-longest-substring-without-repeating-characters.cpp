class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        set<char> st;
        while(r < s.size()){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                maxLen = max(maxLen , r-l+1);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxLen;
        
    }
};