class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k){
            int n = s.size();

            string ans = "";
            for(int i = 0; i < n; i+=k){
                int start = i;
                int end = min(i+k, n);
                int sum = 0;
                for(int j = i; j < end; j++){
                    sum += s[j] - '0';
                }
                ans += to_string(sum);
            }
            s = ans;
        }
        return s;
        
    }
};