class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int depth = 0;
        for(char c : s){
            if(c == '('){
                depth++;
                maxdepth = max(maxdepth, depth);
            }else{
                if(c == ')'){
                    depth--;
                }
            }
            maxdepth = max(maxdepth, depth);

        }
        return maxdepth;
    }
};