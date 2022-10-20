#include <bits/stdc++.h>
using namespace std;


#define TASK "TASK"
#define X first
#define Y second

const int N = 1e4 + 5;
int dp[N][N];
int a[N], b[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = 1; j <= m; ++j) cin >> b[j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[max(0, i - 2)][max(0, j - 2)] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    cout << dp[n][m];
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
