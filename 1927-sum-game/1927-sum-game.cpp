class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int mid = n / 2;
        int left_sum = 0, left_q =0;
        int right_sum = 0, right_q = 0;
        for(int i = 0; i < mid; i++){
            if(num[i] == '?'){
                left_q ++;
            }else{
                left_sum += num[i] - '0';
            }
        }
        for(int i = mid; i < n; i++){
            if(num[i] == '?'){
                right_q++;
            }else{
                right_sum += num[i] - '0';
            }
        }
        return (left_sum - right_sum) != (right_q - left_q) * 9.0 /2;
    }
};