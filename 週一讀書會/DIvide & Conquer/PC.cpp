#include <bits/stdc++.h>
using namespace std;

struct pt
{
    double x, y;
};

bool cmpX(pt p, pt q)
{
    return p.x < q.x;
}
bool cmpY(pt p, pt q)
{
    return p.y < q.y;
}

vector<pt> arr;
double ans = 10000;

double dist(pt p, pt q)
{
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

void calc(int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    calc(l, mid);
    calc(mid + 1, r);

    vector<pt> L, R;

    pt left = arr[mid + 1], right = arr[mid];
    left.x -= ans;
    right.x += ans;

    int start = lower_bound(arr.begin() + l, arr.begin() + mid, left, cmpX) - arr.begin();
    for (int i = start; i <= mid; ++i)
    {
        L.emplace_back(arr[i]);
    }
    int end = lower_bound(arr.begin() + mid + 1, arr.begin() + r, right, cmpX) - arr.begin();
    for (int i = mid + 1; i <= end; ++i)
    {
        R.emplace_back(arr[i]);
    }
    sort(L.begin(), L.end(), cmpY);
    sort(R.begin(), R.end(), cmpY);

    for (int i = 0, j = 0; i < L.size(); ++i)
    {
        while (j > 0 && L[i].y - ans < R[j].y)
        {
            --j;
        }
        while (j < R.size() && L[i].y + ans > R[j].y)
        {
            ans = min(ans, dist(L[i], R[j]));
            ++j;
        }
        if (j == R.size())
            --j;
    }
}

int32_t main()
{
    int n;
    while (cin >> n)
    {
        ans = 10000;
        if (n == 0)
            break;
        arr.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i].x >> arr[i].y;
        }
        sort(arr.begin(), arr.end(), cmpX);
        calc(0, n - 1);
        if (ans == 10000)
            cout << "INFINITY\n";
        else
            printf("%.4lf\n", ans);
    }
    return 0;
}