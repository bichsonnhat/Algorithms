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


#define TASK "CITY"
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
const ll N = 20;
const ll MOD = 1e9 + 7;
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

int p[N], q[N], n, f[(1 << N) + 5], power[N];
bool vis[(1 << N) + 5];
int t, s;
bool GetBit(int x, int i){
    return ((x >> i) & 1);
}
vector <int> adj[N];
pair <int, pair <int, int> > trace[(1 << N) + 5];
void Pre_Compute(){
    for (int i = 2; i <= 7; ++i){
        adj[1].push_back(i);
    }
    vector <int> v = {1, 3, 7, 8, 9, 10};
    for (auto i : v) adj[2].push_back(i);
    v = {1, 2, 4, 10, 11, 12};
    for (auto i : v) adj[3].push_back(i);
    v = {1, 3, 5, 12, 13, 14};
    for (auto i : v) adj[4].push_back(i);
    v = {1, 4, 6, 14, 15, 16};
    for (auto i : v) adj[5].push_back(i);
    v = {1, 5, 7, 16, 17, 18};
    for (auto i : v) adj[6].push_back(i);
    v = {1, 2, 6, 8, 18, 19};
    for (auto i : v) adj[7].push_back(i);
    v = {9, 2, 7, 19};
    for (auto i : v) adj[8].push_back(i);
    v = {8, 2, 10};
    for (auto i : v) adj[9].push_back(i);
    v = {9, 2, 3, 11};
    for (auto i : v) adj[10].push_back(i);
    v = {10, 3, 12};
    for (auto i : v) adj[11].push_back(i);
    v = {11, 3, 4, 13};
    for (auto i : v) adj[12].push_back(i);
    v = {12, 4, 14};
    for (auto i : v) adj[13].push_back(i);
    v = {13, 4, 5, 15};
    for (auto i : v) adj[14].push_back(i);
    v = {14, 5, 16};
    for (auto i : v) adj[15].push_back(i);
    v = {15, 5, 6, 17};
    for (auto i : v) adj[16].push_back(i);
    v = {16, 6, 18};
    for (auto i : v) adj[17].push_back(i);
    v = {17, 6, 7, 19};
    for (auto i : v) adj[18].push_back(i);
    v = {8, 7, 18};
    for (auto i : v) adj[19].push_back(i);
}

void init() {
    power[0] = 1;
    for (int i = 1; i <= 19; i++)
        power[i] = power[i - 1] * 2;
}

int d = 2;

void calc(int x){
    queue <int> q;
    q.push(x);
    trace[x] = {0, {0, 0} };
    vis[x] = true;
//    trace[x] = make_pair(0, make_pair(0, 0));
    while (!q.empty()){
        int u = q.front();
        q.pop();
        if (u == s){
            break;
        }
        for (int i = 1; i <= 19; ++i){
            if (GetBit(u, i)){
                for (auto v : adj[i]){
                    if (!GetBit(u, v)){
                        int k = u - power[i] + power[v];
                        if (!vis[k]) {
                            vis[k] = true;
                            f[k] = f[u] + 1;
                            q.push(k);
                            trace[k] = {u, {i, v}};
                        }
                    }
                }
            }
        }
    }
    cout << f[s] << '\n';
    vector <ii> ans;
    while (trace[s].first != 0){
        ans.push_back(trace[s].second);
        s = trace[s].first;
    }
    reverse(all(ans));
    for (auto x : ans) cout << x.first << ' ' << x.second << '\n';
}
void Solve(){
    cin >> n;
    FOR(i, 1, n) cin >> p[i];
    FOR(i, 1, n) cin >> q[i];
    Pre_Compute();
    init();
    memset(f, 0); memset(vis, 0);
    t = 0;
    s = 0;
    for (int i = 0; i <= (1 << n); ++i)
        trace[i] = {-1, {-1, -1}};
    FOR(i, 1, n) t += power[p[i]];
    FOR(i, 1, n) s += power[q[i]];
    calc(t);
//    cout << calc(t);
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
