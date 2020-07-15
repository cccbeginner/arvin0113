#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
bool isPrime[1000001];
bool cyclePrime[1000001];

int main(){
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i <= 1000000; ++i){
        if(isPrime[i])primes.emplace_back(i);
        for(int j = 0; j < primes.size() && i*primes[j] <= 1000000; ++j){
            isPrime[i * primes[j]] = 0;
            if(i % primes[j] == 0)break;
        }
    }
    for(int i = 2; i <= 1000000; ++i){
        if(!isPrime[i])continue;
        vector<int> digits;
        int x = i;
        while(x){
            digits.emplace_back(x%10);
            x /= 10;
        }
        bool iscircular = 1;
        for(int j = 0; j < digits.size() && iscircular; ++j){
            int num = 0;
            for(int k = digits.size()-1; k >= 0; --k){
                num *= 10;
                num += digits[(k+j) % digits.size()];
            }
            if(!isPrime[num])iscircular = 0;
        }
        if(iscircular)cyclePrime[i] = 1;
    }
    int l,r;
    while(cin >> l){
        if(l == -1)break;
        cin >> r;
        int cnt = 0;
        for(int i = l; i <= r; ++i)cnt += cyclePrime[i];
        if(cnt == 0)cout << "No Circular Primes.\n";
        else if(cnt == 1)cout << "1 Circular Prime.\n";
        else cout << cnt << " Circular Primes.\n";
    }
    return 0;
}