class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node solve(int pos,
               int prev1,
               int prev2,
               int started,
               int tight)
    {
        if(pos == s.size())
        {
            return {1, 0};
        }

        if(!tight && vis[pos][prev1][prev2][started])
            return dp[pos][prev1][prev2][started];

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for(int d = 0; d <= limit; d++)
        {
            int ntight = tight && (d == limit);

            if(!started && d == 0)
            {
                Node nxt =
                    solve(pos + 1,
                          10,
                          10,
                          0,
                          ntight);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav;
            }
            else
            {
                int extra = 0;

                if(started && prev2 != 10)
                {
                    if((prev1 > prev2 && prev1 > d) ||
                       (prev1 < prev2 && prev1 < d))
                    {
                        extra = 1;
                    }
                }

                Node nxt =
                    solve(pos + 1,
                          d,
                          prev1,
                          1,
                          ntight);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav + extra * nxt.cnt;
            }
        }

        if(!tight)
        {
            vis[pos][prev1][prev2][started] = true;
            dp[pos][prev1][prev2][started] = ans;
        }

        return ans;
    }

    long long F(long long x)
    {
        if(x < 0) return 0;

        memset(vis, 0, sizeof(vis));

        s = to_string(x);

        return solve(0, 10, 10, 0, 1).wav;
    }

    long long totalWaviness(long long num1, long long num2)
    {
        return F(num2) - F(num1 - 1);
    }
};