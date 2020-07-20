#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,m,l;
    cin >> n >> m >> l;
    int A = n/l, B = m/l;
    int ans = A*B;
    int a = m%l, b = n%l;
    if(a > b){
        swap(a,b);
        swap(A,B);
    }
    ++A;
    while(B){
        int takeB = min(B, (l/b));
        int takeA = (l-b*takeB)/a;
        B -= takeB;
        A -= takeA;
        ++ans;
    }
    if(A > 0){
        ans += A/(l/a);
        if(A % (l/a) != 0)++ans;
    }
    cout << ans << '\n';
    return 0;
}