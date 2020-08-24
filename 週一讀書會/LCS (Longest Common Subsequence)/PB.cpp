#include <bits/stdc++.h>
using namespace std;

char maze[21][21];

void func(string &s)
{
    s = "";
    int n, x, y;
    char c;
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i)
    {
        s += maze[x][y];
        cin >> c;
        if (c == 'N')
            --x;
        else if (c == 'S')
            ++x;
        else if (c == 'W')
            --y;
        else if (c == 'E')
            ++y;
    }
    s += maze[x][y];
}

vector<int> v[130];
vector<int> ans;

int32_t main()
{
    int t, h, w, n;
    string s1, s2;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        cin >> h >> w;
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                cin >> maze[i][j];
            }
        }
        func(s1);
        func(s2);
        //cout << s1 << endl << s2 << endl;
        for (int i = 33; i <= 127; ++i)
            v[i].clear();
        n = 0;
        ans.clear();
        for (int i = 0; i < s1.size(); ++i)
            v[s1[i]].emplace_back(i);
        for (int i = 0; i < s2.size(); ++i)
        {
            int len = ans.size() - 1;
            for (int j = v[s2[i]].size() - 1; j >= 0; --j)
            {
                for (; len >= 0; --len)
                {
                    if (ans[len] < v[s2[i]][j])
                        break;
                }
                if (len + 1 == ans.size())
                    ans.emplace_back(v[s2[i]][j]);
                else
                    ans[len + 1] = v[s2[i]][j];
            }
        }
        cout << "Case " << k << ": " << s1.size() - ans.size() << ' ' << s2.size() - ans.size() << '\n';
    }
    return 0;
}