class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<int>last(26);
        for(int i = 0; i < n; i++){
            last[s[i] - 'a'] = i;   
        }
        vector<bool>visited(26, false);
        stack<int>st;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(visited[ch - 'a']){
                continue;
            }
            while(!st.empty() && st.top() > ch && last[st.top()-'a'] > i){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            visited[ch - 'a'] = true;
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};