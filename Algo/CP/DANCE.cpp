#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ll;

const int N = 1e3 + 5;
const long long oo = 1e12;

long long dp[N][N];
int a[N];
int n, k;

int main() {
    ios::sync_with_stdio(0);
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = oo;
    sort(a + 1, a + 1 + n);
    dp[0][0] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i / 2; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + (a[i] - a[i - 1]));
        }
    long long res = 1e12;
    for (int i = 1; i <= n; i++)
        res = min(res, dp[i][k]);
    cout << res;
}
