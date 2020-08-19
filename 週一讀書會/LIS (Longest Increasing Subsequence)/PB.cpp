#include <bits/stdc++.h>
using namespace std;

struct pir
{
    int val, idx;
    bool operator<(const pir &x) const { return val < x.val; }
};
vector<pir> arr, v;
vector<int> track, ans;

int main()
{
    int x;
    while (cin >> x)
    {
        pir in = {.val = x, .idx = arr.size()};
        arr.emplace_back(in);
    }
    track.resize(arr.size(), -1);
    v.emplace_back(arr[0]);
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i].val > v.back().val)
        {
            track[i] = v.back().idx;
            v.emplace_back(arr[i]);
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            (*it) = arr[i];
            if (it != v.begin())
            {
                --it;
                track[i] = (*it).idx;
                ++it;
            }
        }
    }
    cout << v.size() << "\n-\n";
    x = v.back().idx;
    while (~x)
    {
        ans.emplace_back(arr[x].val);
        x = track[x];
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << '\n';
    return 0;
}