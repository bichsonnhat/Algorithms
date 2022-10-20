#include <bits/stdc++.h>
using namespace std;


#define TASK "DIVEPA"
#define X first
#define Y second

const int MOD = 1e9 + 7;

vector <long long> fact(1000005);
long long pw(long long x, long long y){
    if (y == 0){
        return 1;
    }
    long long t = pw(x, y / 2) % MOD;
    if (y % 2) return x * t % MOD * t % MOD;
    return t * t % MOD;
}
long long C(long long n, long long k){
    if (k > n) return 0;
    /// a / b % MOD = a * b^ MOD
    return (fact[n] % MOD * pw(fact[n] * fact[n - k] % MOD, MOD - 2) % MOD) % MOD;
}
void Solve(){
    int n, k; cin >> n >> k;
    vector <int> a(n + 1);
    vector <long long> pref(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        fact[i] = fact[i - 1] * i % MOD;
    }
    if (pref[n] == 0){
        int cnt = 0;
        for (int i = 1; i <= n; ++i){
            if (pref[i] == 0){
                ++cnt;
            }
        }
        cout << C(cnt - 1, k - 1) << '\n';
        return;
    }
    if (pref[n] % k){
        cout << 0 << '\n';
        return;
    }
    long long s = pref[n] / k;
    map <long long, int> ans;
//    vector <long long> ans(n + 1);
    ans[0] = 1;
    for (int i = 1; i <= n; ++i){
        if (pref[i] % s == 0){
            long long t = pref[i] / s;
            ans[t] = (ans[t] + ans[t - 1]) % MOD;
        }
    }
    cout << ans[k - 1] << '\n';
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
    return 0;
}
