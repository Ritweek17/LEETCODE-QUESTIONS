class Solution {
public:
    struct Node {
        long long ways;
        long long wave;
    };

    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(string &s, int pos, int prev2, int prev1,
             bool started, bool tight) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][started]) {
            return dp[pos][prev2][prev1][started];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool newTight = tight && (d == limit);

            if (!started && d == 0) {

                Node cur = dfs(
                    s, pos + 1,
                    10, 10,
                    false, newTight
                );

                ans.ways += cur.ways;
                ans.wave += cur.wave;
            }
            else {

                long long add = 0;

                if (started && prev2 != 10 && prev1 != 10) {

                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                Node cur = dfs(
                    s, pos + 1,
                    started ? prev1 : 10,
                    d,
                    true, newTight
                );

                ans.ways += cur.ways;
                ans.wave += cur.wave + add * cur.ways;
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][started] = true;
            dp[pos][prev2][prev1][started] = ans;
        }

        return ans;
    }

    long long calc(long long n) {

        if (n <= 0)
            return 0;

        string s = to_string(n);

        memset(vis, false, sizeof(vis));

        return dfs(s, 0, 10, 10, false, true).wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};