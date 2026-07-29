class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while(r < s.size()){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                maxlen = max(maxlen , r-l+1);
                r++;
            }else {
                st.erase(s[l]);
                l++;
            }
        }
        return maxlen;
        
    }
};