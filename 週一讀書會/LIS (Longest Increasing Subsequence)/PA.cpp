#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

struct block
{
    pii area;
    int h;
} B[90];

bool cmp(const block &a, const block &b)
{
    return a.area < b.area;
}

int dp[90];

int main()
{
    int n, a, b, c, cnt = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b >> c;
            B[i * 3].area = (a < b) ? make_pair(a, b) : make_pair(b, a);
            B[i * 3].h = c;
            B[i * 3 + 1].area = (b < c) ? make_pair(b, c) : make_pair(c, b);
            B[i * 3 + 1].h = a;
            B[i * 3 + 2].area = (a < c) ? make_pair(a, c) : make_pair(c, a);
            B[i * 3 + 2].h = b;
        }
        n *= 3;
        sort(B, B + n, cmp);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = B[i].h;
            for (int j = 0; j < i; ++j)
            {
                if (B[i].area.first > B[j].area.first && B[i].area.second > B[j].area.second)
                    dp[i] = max(dp[i], dp[j] + B[i].h);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(dp[i], ans);
        cout << "Case " << ++cnt << ": maximum height = " << ans << '\n';
    }
    return 0;
}