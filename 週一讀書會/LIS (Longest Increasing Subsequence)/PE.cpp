#include <bits/stdc++.h>
using namespace std;

struct box
{
    vector<int> lens;
    int idx;
};

vector<box> boxes;

bool cmp(box p, box q)
{
    return p.lens[0] < q.lens[0];
}

bool bigger(box p, box q) //p fully bigger than q
{
    for (int i = 0; i < p.lens.size(); ++i)
    {
        if (p.lens[i] <= q.lens[i])
            return false;
    }
    return true;
}

int dp[1000]; //I don't know what the maxsize is. So I use 1000.
int back[1000];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        memset(back, -1, sizeof(back));
        boxes.clear();
        for (int i = 0; i < n; ++i)
        {
            box tmd;
            tmd.idx = i + 1;
            for (int j = 0; j < m; ++j)
            {
                int x;
                cin >> x;
                tmd.lens.emplace_back(x);
            }
            sort(tmd.lens.begin(), tmd.lens.end());
            boxes.emplace_back(tmd);
        }
        sort(boxes.begin(), boxes.end(), cmp);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (bigger(boxes[i], boxes[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    back[i] = j;
                }
            }
        }
        int tar = 0;
        for (int i = 1; i < n; ++i)
        {
            if (dp[tar] < dp[i])
            {
                tar = i;
            }
        }
        cout << dp[tar] + 1 << '\n';
        vector<int> ans;
        while (tar != -1)
        {
            ans.emplace_back(boxes[tar].idx);
            tar = back[tar];
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i != 0)
                cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}