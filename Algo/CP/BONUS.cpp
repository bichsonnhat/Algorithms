#include <bits/stdc++.h>

using namespace std;

//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
//typedef tree< double, int, less<double>, rb_tree_tag, tree_order_statistics_node_update> map_t;

/// Shortcut

#define TASK "BONUS"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORTYPE(type, i, l, r) for (type i = l; i <= r; i++)
#define FODTYPE(type, i, l, r) for (type i = l; i >= r; i--)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define FORAUTO(i, a) for (auto i : a)

/// Functions

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define upper upper_bound
#define lower lower_bound
#define itr iterator
#define rtr reverse_iterator
#define memset(a,x) memset(a, x, sizeof(a))
#define memsetf(a) memset(a, 0x3f, sizeof(a))
#define fillV(v, x) fill(v.begin(), v.end(), x)
#define fillArr(arr, n, x) fill(arr, arr + n, x)
#define fillA(a, n, x) fill(a + 1, a + n + 1, x)

/// Data Structure

#define um unordered_map
#define us unordered_set
#define pq priority_queue

/// BIT

#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

/// EDIT

const ll N = 5e2 + 1;
const ll MOD = 1e9 + 7;
const ll BASE = 1000;
const ll DIGIT = 4;
const ll LIM = (1 << 24);
const ll INF = (1 << 30);
const ll LIMIT = 1e18;

/// ================================ - MAIN - ================================

int m, n, q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    cin >> m >> n >> q;
    int a[m + 5][n + 5];
    ll pre[m + 5][n + 5];
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            a[i][j] = 0, pre[i][j] = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        pre[0][i] = a[0][i];
    for (int i = 1; i < m; ++i)
        for (int j = 0; j < n; ++j)
            pre[i][j] = a[i][j] + pre[i - 1][j];
    for (int i = 0; i < m; ++i)
        for (int j = 1; j < n; ++j)
            pre[i][j] += pre[i][j - 1];
    while (q --> 0){
        int x, y, u, k;
        cin >> x >> y >> u >> k;
        --x, --y, --u, --k;
        long long res = pre[u][k];
        if (x > 0)
           res = res - pre[x-1][k];
        if (y > 0)
           res = res - pre[u][y-1];
        if (x > 0 && y > 0)
        res = res + pre[x-1][y-1];
        cout << res << '\n';
    }
    return 0;
}
