#include <bits/stdc++.h>
using namespace std;

struct nums
{
    int x, y, z, idx, ans;
} arr[100001];

bool cmpIDX(nums p, nums q)
{
    return p.idx < q.idx;
}
bool cmpX(nums p, nums q)
{
    return p.x < q.x;
}
bool cmpY(nums p, nums q)
{
    return p.y < q.y;
}

// fenwick tree
int BIT[100001];
int n;
void add(int k, int val)
{
    if (k > n)
        return;
    BIT[k] += val;
    add(k + (k & (-k)), val);
}
int sum(int k)
{
    if (k <= 0)
        return 0;
    return BIT[k] + sum(k - (k & (-k)));
}

// cdq
void counts(int l, int r) //[l,r]
{
    // find a place to split
    // it guarantee that arr[i].x < arr[j].x
    // for every l <= i <= mid, mid < j <= r
    int mid = l - 1;
    for (int i = l; i < r && mid <= (l + r) / 2; ++i)
    {
        if (arr[i].x != arr[i + 1].x)
        {
            mid = max(mid, i);
        }
    }
    if (mid == l - 1)
        return;

    // split & count themselves
    counts(l, mid);
    counts(mid + 1, r);
    sort(arr + l, arr + mid + 1, cmpY);
    sort(arr + mid + 1, arr + r + 1, cmpY);

    // counting (the left side only)
    int i, j;
    for (i = mid, j = r; i >= l; --i)
    {
        while (j > mid && arr[i].y < arr[j].y)
        {
            add(n + 1 - arr[j].z, 1);
            --j;
        }
        arr[i].ans += sum(n - arr[i].z);
    }

    // setup to 0
    while (j < r)
    {
        ++j;
        add(n + 1 - arr[j].z, -1);
    }
}

int32_t main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
        arr[i].idx = i;
        arr[i].ans = 0;
    }
    sort(arr, arr + n, cmpX);
    counts(0, n - 1);
    sort(arr, arr + n, cmpIDX);
    for (int i = 0; i < n; ++i)
        cout << arr[i].ans << '\n';

    return 0;
}