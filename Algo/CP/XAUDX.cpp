#include <bits/stdc++.h>
using namespace std;


const int N = 1e3 + 5;
#define TASK "XAUDX"
#define X first
#define Y second

int dp[N][N];
void Solve(){
    string s;
    cin >> s;
    int n = (int) (s.size());
    s = "#" + s;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = n; j >= 1; --j){
            if (s[i] == s[j]){
                dp[i][j] = dp[i - 1][j + 1] + 1;
            } else dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
            ans = max(ans, dp[i][j]);
        }
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
    int ntests = 1;
//    cin >> ntests;
    while (ntests--) Solve();
    return 0;
}
