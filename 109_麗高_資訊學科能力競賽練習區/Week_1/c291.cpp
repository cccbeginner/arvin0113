#include<bits/stdc++.h>
using namespace std;

bool vis[50000];
int friends[50000];

void fill(int k){
    if(vis[k] == 1)return;
    vis[k] = 1;
    fill(friends[k]);
}

int main(){
    int n, cnt;
    while(cin >> n){
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; ++i)cin >> friends[i];
        for(int i = 0; i < n; ++i){
            if(vis[i] == 1)continue;
            ++cnt;
            fill(i);
        }
        cout << cnt << '\n';
    }
    return 0;
}