class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int n = moves.size();
        int count = 0;int l=0,r=0,d=0;

        for(int i = 0; i < n; i++){
            if(moves[i] == 'L'){
                l++;
            }
           else if(moves[i] == 'R'){
                r++;
            }
            else{
                d++;
            }
        } 

        if(l<=r){
            count=r+d-l;
        }
        else{
            count=abs(r-l-d);
        }
        return count;
    }
};