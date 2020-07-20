#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[1000][1000];
int dx[] = {-1,1,1,-1};
int dy[] = {1,1,-1,-1};

int32_t main(){
    int n,m,x,y,d;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[j][i];
        }
    }
    cin >> x >> y >> d;
    --d;
    --x;
    --y;
    int ans = 0;
    for(int cnt = 0; cnt < 4; ++cnt){
        while(1){
            ans += arr[x][y];
            int nx = x+dx[d];
            int ny = y+dy[d];
            if((nx < 0 || nx >= n) && (ny < 0 || ny >= m)){
                d = (d+2)%4;
                break;
            }else if(nx < 0 || nx >= n){
                y = ny;
                if(d == 0 || d == 2)++d;
                else --d;
                break;
            }else if(ny < 0 || ny >= m){
                x = nx;
                if(d == 0 || d == 2)d = (d+3)%4;
                else d = (d+1)%4;
                break;
            }else{
                x = nx;
                y = ny;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}