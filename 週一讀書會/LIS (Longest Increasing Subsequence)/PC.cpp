#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int big[10000], small[10000]; //ascend, descend

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        vector<int> v1, v2;
        v1.emplace_back(arr[0]);
        big[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] > v1.back())
            {
                big[i] = v1.size() + 1;
                v1.emplace_back(arr[i]);
            }
            else
            {
                auto it = lower_bound(v1.begin(), v1.end(), arr[i]);
                big[i] = it - v1.begin() + 1;
                (*it) = arr[i];
            }
        }
        v2.emplace_back(arr[n - 1]);
        small[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (arr[i] > v2.back())
            {
                small[i] = v2.size() + 1;
                v2.emplace_back(arr[i]);
            }
            else
            {
                auto it = lower_bound(v2.begin(), v2.end(), arr[i]);
                small[i] = it - v2.begin() + 1;
                (*it) = arr[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, min(big[i], small[i]));
        cout << ans * 2 - 1 << '\n';
    }
    return 0;
}