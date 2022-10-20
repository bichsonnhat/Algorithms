#include <bits/stdc++.h>
using namespace std;

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
//typedef tree< double, int, less<double>, rb_tree_tag, tree_order_statistics_node_update> map_t;


#define TASK "TASK"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORTYPE(type, i, l, r) for (type i = l; i <= r; i++)
#define FODTYPE(type, i, l, r) for (type i = l; i >= r; i--)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define prec(n) fixed<<setprecision(n)
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
#define um unordered_map
#define us unordered_set
#define pq priority_queue
#define GetMask ((x >> i) & 1)
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
const ll N = 3e5 + 5;
const ll MOD = 998244353;
const ll BASE = 1000;
const ll DIGIT = 4;
const ll LIM = (1 << 24);
const ll INF = (1 << 30);
const ll LIMIT = 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
const int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int oo = 1e9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll binPow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return binPow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
//mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
//inline int mrand() {return abs((int) mt());}
//inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

/// ================================ - MAIN - ================================

int n, m, x, y;
vector <ii> road;
vector <int> adj[N];
vector <int> pub;
bool vis[N];

void Init(){
    for (int i = 1; i <= n; ++i){
        adj[i].clear();
        vis[i] = false;
    }
    pub.clear();
    road.clear();
}
void DFS(int u){
    vis[u] = true;
    pub.push_back(u);
    for (auto v : adj[u]){
        if (!vis[v]) {
            DFS(v);
        }
    }
}

bool match(int a, int b, int c, int d){
    if (a == c && b == d){
        return true;
    }
    if (a == d && b == c){
        return true;
    }
    return false;
}
void DFS_road(int u){
    vis[u] = true;
    pub.push_back(u);
    for (auto v : adj[u]){
        if (!match(u, v, x, y) && !vis[v]){
            DFS_road(v);
        }
    }
}
void Subtask_12(){
    for (int i = 1; i <= n; ++i){
        /// Delete city i
        memset(vis, 0);
        long long ans = 0;
        vis[i] = true;
        pub.clear();
        for (int j = 1; j <= n; ++j){
            if (!vis[j]) {
                DFS(j);
                int city = (int) (pub.size());
                int rem = n - city - 1;
                ans = (ans % MOD) + 1LL * city * rem;
                ans = (ans + MOD) % MOD;
                break;
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; ++i){
        x = road[i].first;
        y = road[i].second;
        /// Delete road (x, y).
        pub.clear();
        long long ans = 0;
        memset(vis, 0);
        for (int j = 1; j <= n; ++j){
            if (!vis[j]){
                DFS_road(j);
                int city = (int) (pub.size());
                int rem = n - city;
                ans = (ans % MOD) + 1LL * city * rem;
                ans = (ans + MOD) % MOD;
                break;
            }
        }
        cout << ans << ' ';
    }
    return;
}
void Solve(){
    cin >> n >> m;
    Init();
    for (int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        road.push_back({u, v});
    }
    if (n <= 3000 && m <= 3000) {
        Subtask_12();
        return;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int ntest = 1;
    cin >> ntest;
    while (ntest--){
        Solve();
    }
}
