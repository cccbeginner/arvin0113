#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int k){
    if(k < 2)return 0;
    for(int i = 2; i <= sqrt(k); ++i){
        if(k % i == 0)return 0;
    }
    return 1;
}

int32_t main(){
    string s;
    bool begin=1;
    while(cin >> s){
        if(begin)begin=0;
        else cout << '\n';
        vector<int> primes;
        int num = 0;
        for(int i = 0; i < s.size(); ++i){
            num = num * 10 + s[i]-'0';
            if(isPrime(num)){
                primes.emplace_back(num);
                num = 0;
            }
        }
        cout << primes.size() << '\n';
        for(int i = 0; i < primes.size(); ++i){
            cout << primes[i] << '\n';
        }
    }
    return 0;
}