class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        if(n %2 != 0){
            return false;
        }

        return true;
    }
};