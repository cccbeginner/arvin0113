#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<char> rec;
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); ++i){
            if(!rec.empty() && rec.back() == '(' && s[i] == ')')rec.pop_back();
            else rec.emplace_back(s[i]);
        }
        if(rec.empty())cout << s.size() / 2 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
