#include <bits/stdc++.h>
using namespace std;

struct stat
{
    int x, y;
    string cur;
    bool operator<(const stat &rhs) const
    {
        if (x != rhs.x)
            return x < rhs.x;
        if (y != rhs.y)
            return y < rhs.y;
        return cur < rhs.cur;
    }
};

int dp[33][33];
string s1, s2;
set<string> v;
set<stat> vis;

void dfs(int x, int y, string cur)
{
    if (cur.size() + dp[x][y] < dp[0][0])
        return;
    stat tmd = {.x = x, .y = y, .cur = cur};
    if (vis.find(tmd) != vis.end())
        return;
    else
        vis.insert(tmd);
    //cout << x << ' ' << y << ' ' <<cur << endl;
    if (cur.size() == dp[0][0])
    {
        v.insert(cur);
    }
    else
    {
        if (s1[x] == s2[y])
            dfs(x + 1, y + 1, cur + s1[x]);
        else
        {
            dfs(x, y + 1, cur);
            dfs(x + 1, y, cur);
        }
    }
}

int32_t main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        v.clear();
        vis.clear();
        memset(dp, 0, sizeof(dp));
        cin >> s1 >> s2;
        for (int i = s1.size() - 1; i >= 0; --i)
        {
            for (int j = s2.size() - 1; j >= 0; --j)
            {
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        dfs(0, 0, "");
        printf("Case #%d: %d\n", k, v.size());
        for (auto it = v.begin(); it != v.end(); ++it)
            cout << (*it) << '\n';
    }
    return 0;
}