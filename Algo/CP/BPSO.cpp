#include <bits/stdc++.h>
using namespace std;


#define TASK "BPSO"
#define X first
#define Y second

long long f(long long n){
    long long res = 0;
    while (n){
        res += 1LL * (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}
void Solve(){
    long long x; int n; cin >> x >> n;
    for (int i = 1; i < n; ++i){
        x = f(x);
    }
    cout << x << '\n';
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
