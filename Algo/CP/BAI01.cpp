#include <bits/stdc++.h>
using namespace std;


#define TASK "BAI01"
#define X first
#define Y second

void Solve(){
    int l, r, a, b; cin >> l >> r >> a >> b;
    int g = __gcd(a, b);
    int lcm = (a * b) / g;
    cout << (r / lcm) - (l - 1) / lcm << '\n';
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
