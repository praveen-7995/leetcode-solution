class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string>digits;
        for(int num : nums){
            digits.push_back(to_string(num));
        }
        sort(digits.begin(), digits.end(), [](string &a, string &b){
            return a + b > b + a;
        });
        if(digits[0] == "0") return "0";

        string result = "";
        for(string &s : digits){
            result += s;
        }
        return result;
        
    }
};