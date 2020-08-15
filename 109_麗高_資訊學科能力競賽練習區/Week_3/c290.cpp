#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans[2] = {0};
    for (int i = 0; i < s.size(); ++i)
        ans[(i & 1)] += s[i] - '0';
    cout << abs(ans[0] - ans[1]) << '\n';
}