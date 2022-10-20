#include <bits/stdc++.h>
#define ll long long
#define pii pair<long long, long long>
#define ull unsigned long long
#define st first
#define nd second
#define file "BUYING"
using namespace std;
const long long oo = 1e18;
const long long N = 3e3 + 5;

struct data
{
    ll b, c;

    bool operator <(data other){
        return b - c < other.b - other.c;
    }
} g[N];

ll a[N], n, f[N][N], p[N][N], f1[N], p1[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen(file".inp","r",stdin);
//        freopen(file".out","w",stdout);
//    #endif

    cin >> n;

    ll sum_a = 0;

    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> g[i].b >> g[i].c;
        g[i].b -= a[i];
        g[i].c -= a[i];
        sum_a += a[i];
    }

    sort(g + 1, g + 1 + n);

    for (int i = 0; i <= n + 1; i ++)
        for (int j = 0; j <= n + 1; j ++)
            p[i][j] = f[i][j] = oo;

    f[0][0] = p[n+1][0] = 0;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            f[i][j] = min(f[i-1][j], f[i-1][j-1] + g[i].b - j + 1);

    for (int i = n; i >= 1; i --)
        for (int j = 1; j <= n - i + 1; j ++)
            p[i][j] = min(p[i+1][j], p[i+1][j-1] + g[i].c - j + 1);

    ll ans = oo;

    for (int i = 0; i <= n; i ++){
        ll sum_f = 0, sum_p = 0;
        for (int j = 0; j <= n; j ++){
            sum_f = min(sum_f, f[i][j]);
            sum_p = min(sum_p, p[i+1][j]);
        }
        ans = min({ans, sum_p, sum_f, sum_p + sum_f});
    }

    cout << ans + sum_a;
    return 0;
}
