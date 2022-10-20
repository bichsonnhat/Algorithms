#include <bits/stdc++.h>
using namespace std;


#define TASK "FUNCTION"
#define X first
#define Y second
#define ll long long

const int N = 1e5 + 5;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
long long a[N];
set <long long> s;
void Solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], s.insert(a[i]);
    for (int i = 1; i < n; ++i){
        if (i > 1){
            if (gcd(a[i], a[i + 1]) == gcd(a[i - 1], a[i])) continue;
        }
        long long g = a[i];
        for (int j = i + 1; j <= n; ++j){
            g = gcd(g, a[j]);
            s.insert(g);
            if (g == 1) break;
        }
    }
    cout << s.size() << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int ntests = 1;
//    cin >> ntests;
    while (ntests--) Solve();
    return 0;
}
