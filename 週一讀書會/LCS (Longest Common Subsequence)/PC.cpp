#include <bits/stdc++.h>
using namespace std;

int dp[22][22];
int track[22][22]; //0 := copy, 1 := →, 2 := ↓, 3 := ↘

string s1, s2;

void back(int x, int y)
{
    //cout << x << ' ' << y << ' ' << endl;
    if (x == 0 && y == 0)
        return;
    if (track[x][y] == 0)
        back(x - 1, y - 1);
    else if (track[x][y] == 1)
    {
        back(x, y - 1);
        printf("I%c%02d", s2[y], y);
    }
    else if (track[x][y] == 2)
    {
        back(x - 1, y);
        printf("D%c%02d", s1[x], y + 1);
    }
    else if (track[x][y] == 3)
    {
        back(x - 1, y - 1);
        printf("C%c%02d", s2[y], y);
    }
}

int32_t main()
{
    for (int i = 1; i <= 20; ++i)
    {
        track[0][i] = 1;
        track[i][0] = 2;
        dp[0][i] = dp[i][0] = i;
    }
    while (cin >> s1 >> s2)
    {
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        for (unsigned i = 1; i < s1.size(); ++i)
        {
            for (unsigned j = 1; j < s2.size(); ++j)
            {
                dp[i][j] = 1e9;
                if (s1[i] == s2[j])
                {
                    track[i][j] = 0;
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    track[i][j] = 3;
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j - 1] + 1 < dp[i][j])
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                    track[i][j] = 1;
                }
                if (dp[i - 1][j] + 1 < dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j] + 1;
                    track[i][j] = 2;
                }
            }
        }
        /*for(int i = 1; i < s1.size(); ++i){
            for(int j = 1; j < s2.size(); ++j)cout << dp[i][j] << ' ';
            cout << '\n';
        }*/
        back(s1.size() - 1, s2.size() - 1);
        cout << "E\n";
    }
    return 0;
}