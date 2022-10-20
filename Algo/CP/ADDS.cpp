#include <bits/stdc++.h>
using namespace std;


#define TASK "ADDS"
#define X first
#define Y second

long long a, b, m, ans;
long long fpow(long long x, long long y, long long MOD){
    long long tmp;
    if (!y) return 1;
    tmp = fpow(x, y / 2, MOD);
    if (y % 2) return x * tmp % MOD * tmp % MOD;
        else return tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    /// n * (n + 1) * (2n + 1) / 6
    cin >> a >> b >> m;
    long long MOD = m * 6;
    ans = (2 * fpow(b, 3, MOD) % MOD + 3 * fpow(b, 2, MOD) % MOD + b % MOD) % MOD;
    a -= 1;
    ans -= ((2 * fpow(a, 3, MOD) % MOD + 3 * fpow(a, 2, MOD) % MOD + a % MOD) % MOD);
    if (ans < 0) ans += MOD;
    ans /= 6;
    cout << ans;
}
