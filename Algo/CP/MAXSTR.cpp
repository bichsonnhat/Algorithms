#include <bits/stdc++.h>
using namespace std;

#define TASK "MAXSTR"

void Solve(){
    string s; cin >> s;
    int ans = 0;
    int n = (int) s.size();
    for (int i = 0; i + 1 < n; ++i){
        int cnt = 1;
        set <char> S;
        S.insert(s[i]);
        for (int j = i + 1; j < n; ++j){
            S.insert(s[j]);
            int sz = (int) S.size();
            if (j - i + 1 != sz) break;
        }
        ans = max(ans, (int) S.size());
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int ntest = 1;
//    cin >> ntest;
    while (ntest--){
        Solve();
    }
}
