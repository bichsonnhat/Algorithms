#include <bits/stdc++.h>
using namespace std;


#define TASK "STIS"
#define X first
#define Y second

const int N = 1025;
int cntA[N], cntB[N];
long long cnt[2 * N];
void Solve(){
    int m, n, x;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) cin >> x, ++cntA[x];
    for (int i = 1; i <= n; ++i) cin >> x, ++cntB[x];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j){
            cnt[i + j] += 1LL * cntA[i] * cntB[j];
        }
    for (int i = 0; i < 2 * N; ++i){
        if (cnt[i]) cout << i << " - " << cnt[i] << '\n';
    }
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
