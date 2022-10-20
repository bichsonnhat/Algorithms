#include <bits/stdc++.h>
using namespace std;

#define TASK "MODK"

long long pw(long long a, long long b, long long mod){
    if (b == 0) return 1;
    int t = pw(a, b / 2, mod) % mod;
    if (b % 2) return a * t % mod * t % mod;
    return t % mod * t % mod;
}
void Solve(){
    long long a, k, x; cin >> a >> k >> x;
    long long rem = 1;
    for (int i = 1; i <= x; ++i){
        rem *= 10;
    }
    cout << pw(a, k, rem) << '\n';
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
