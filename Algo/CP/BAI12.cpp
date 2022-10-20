#include <bits/stdc++.h>
using namespace std;


#define TASK "BAI12"
#define X first
#define Y second

void Solve(){
    int n; cin >> n;
    cout << 1 << ' ' << n << '\n';
    int res = 0, x, y;
    for (int i = n / 2; i >= 1; --i){
        if (res < __gcd(i, n - i)) {
            res = __gcd(i, n - i);
            x = i;
            y = n - i;
        }
    }
    cout << x << " " << y << " " << res;
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

