class Solution {
public:
    void expand(int l, int r, string &s, vector<string> & ans){

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            ans.push_back(s.substr(l, r-l+1));
            l--;
            r++;
        }

    }
    int countSubstrings(string s) {

        vector<string> ans;
        for(int i = 0; i < s.size(); i++){
            expand(i, i, s, ans);
            expand(i, i+1, s, ans);
        }

        return ans.size();
        
    }
};