#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<int> idx[62501];

bool cmp(pii p, pii q)
{
    if (p.first == q.first)
        return p.second > q.second;
    return p.first < q.first;
}

int main()
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; ++c)
    {
        int n, p, q;
        cin >> n >> p >> q;
        for (int i = 0; i <= p; ++i)
        {
            int x;
            cin >> x;
            idx[x].emplace_back(i);
        }
        for (int i = 0; i <= q; ++i)
        {
            int x;
            cin >> x;
            idx[x].emplace_back(i);
        }
        vector<pii> pairs;
        for (int i = 1; i <= n * n; ++i)
        {
            if (idx[i].size() == 2)
                pairs.emplace_back(make_pair(idx[i][0], idx[i][1]));
            idx[i].clear();
        }
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp2;
        for (int i = 0; i < pairs.size(); ++i)
        {
            int val = pairs[i].second;
            if (dp2.empty() || val > dp2.back())
                dp2.emplace_back(val);
            else
                *lower_bound(dp2.begin(), dp2.end(), val) = val;
        }
        cout << "Case " << c << ": " << dp2.size() << '\n';
    }
    return 0;
}