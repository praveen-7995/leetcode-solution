class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        if(cost1 + cost2 <= costBoth){
            return (1ll * cost1 * need1) + (1ll * cost2 * need2);
        }
        int both = min(need1, need2);
        ll total = 1ll * costBoth * both;
        need1 -= both;
        need2 -= both;
        if(need1 > 0){
            total += 1ll * need1 * min(cost1 , costBoth);
        }
        if(need2 > 0){
            total += 1ll * need2 * min(cost2, costBoth);
        }
        return total;
    }
};