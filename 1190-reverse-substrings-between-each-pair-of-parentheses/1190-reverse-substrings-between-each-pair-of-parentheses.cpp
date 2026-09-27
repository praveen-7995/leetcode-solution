class Solution {
public:
    string reverseParentheses(string s) {

        string rev = "";

        vector<int>openbracket;
        for(char c : s){
            if(c == '('){
                openbracket.push_back(rev.length());
            }
            else if(c == ')'){
                int startIdx = openbracket.back();
                openbracket.pop_back();
                reverse(rev.begin() + startIdx, rev.end());
            }else{
                rev += c;
            }
        }
        return rev;
        
    }
};