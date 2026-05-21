class Solution {
public:
    bool checkValidString(string s) {
        int maxopen = 0; 
        int maxclose = 0;
        for(char ch : s){
            if(ch == '('){
                maxopen++;
                maxclose++;
            }else if(ch == ')'){
                maxopen--;
                maxclose--;
            }else{
                maxopen--;
                maxclose++;
            }
            if(maxclose < 0){
                return false;
            }
            if(maxopen < 0){
                maxopen = 0;
            }
        }
        return maxopen == 0;
    }
};