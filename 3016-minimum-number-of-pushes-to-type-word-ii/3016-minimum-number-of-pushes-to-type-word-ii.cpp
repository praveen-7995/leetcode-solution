class Solution {
public:
    int minimumPushes(string word) {

        vector<int>freq(26, 0);

        for(char c : word){
            freq[c - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());

        int char_product = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) break;
            int max_product = (i / 8) + 1;
            char_product += freq[i] * max_product;
        }
        return char_product;
        
    }
};