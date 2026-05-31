class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());
        long long Curr = mass;
        for(int asteroid : asteroids){
            if(Curr < asteroid){
                return false;
            }
            Curr += asteroid;
        }
        return true;
        
    }
};