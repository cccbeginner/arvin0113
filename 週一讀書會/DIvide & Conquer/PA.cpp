#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> arr;
int counts(int l, int r) //[l,r]
{
    // there is one element only
    if (l == r)
        return 0;

    // setup return value
    int ret = 0;

    // split to two subarray and count themself
    int mid = (l + r) / 2;
    ret += counts(mid + 1, r);
    ret += counts(l, mid);
    // array L stands for

    // prevent from overflow arr[l ~ mid]
    // array R stands for arr[mid+1 ~ r]
    // copy value from 'arr' to 'L' & 'R'
    vector<int> L, R;
    for (int i = l; i <= mid; ++i)
        L.emplace_back(arr[i]);
    for (int i = mid + 1; i <= r; ++i)
        R.emplace_back(arr[i]);

    // prevent from overflow
    // every element in 'L' will not bigger than 1e18
    R.emplace_back(1e18);

    // counting & sorting at a time
    for (int i = 0, j = 0; i < L.size(); ++i)
    {
        while (L[i] > R[j] && j < R.size() - 1)
        {
            arr[i + j + l] = R[j];
            ++j;
        }
        ret += j;
        arr[i + j + l] = L[i];

        // //
        while (i == mid && j + mid + 1 <= r)
        {
            arr[j + mid + 1] = R[j];
            ++j;
        }
    }

    return ret;
}

int32_t main()
{
    int n, cnt = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        arr.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int ans = counts(0, n - 1);
        cout << "Case #" << ++cnt << ": " << ans << '\n';
    }

    return 0;
}