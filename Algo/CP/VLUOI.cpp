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
typedef pair<ll, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
//typedef tree< double, int, less<double>, rb_tree_tag, tree_order_statistics_node_update> map_t;


#define TASK "VLUOI"
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
const ll N = 1e3 + 5;
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
const long long oo = 1e18;
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

int a[N][N];
int n, m;
vector <int> par(N * N + 5);
vector <ii> adj[N * N];
long long d[N * N];
int cnt[N * N];
bool vis[N * N], board[N][N];
int val[N * N];
int get_root(int u){
    if (par[u] == u) return u;
    return (par[u] = get_root(par[u]));
};

void join(int u, int v){
    par[get_root(v)] = get_root(u);
};

bool diff(int u, int v){
    return get_root(u) != get_root(v);
};

bool isCell(int r, int c){
    return (r >= 1 && c >= 1 && r <= n && c <= m);
}

void BFS(int u, int v, int root){
    queue <ii> q;
    q.push({u, v});
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        board[r][c] = true;
        q.pop();
        for (int dir = 0; dir < 4; ++dir){
            int new_r = r + dx[dir];
            int new_c = c + dy[dir];
            if (isCell(new_r, new_c) && !board[new_r][new_c] && a[new_r][new_c] == a[u][v]){
                par[(new_r - 1) * m + new_c] = root;
                board[new_r][new_c] = true;
                q.push({new_r, new_c});
            }
        }
    }
}
void Pre_Compute(){
    FOR(i, 1, n){
        FOR(j, 1, m){
            if (!board[i][j]){
                BFS(i, j, (i - 1) * m + j);
            }
        }
    }
//            int u = (i - 1) * m + j;
//            for (int dir = 0; dir < 4; ++dir){
//                int new_i = i + dx[dir];
//                int new_j = j + dy[dir];
//                if (!isCell(new_i, new_j)) continue;
//                int v = (new_i - 1) * m + new_j;
//                if (a[i][j] == a[new_i][new_j]){
//                    join(u, v);
//                    join(v, u);
//                }
//            }
//        }
    /// Create graph
    FOR(i, 1, n){
        FOR(j, 1, m){
            int node = (i - 1) * m + j;
            ++cnt[par[node]];
            if (par[node] == node){
                val[node] = a[i][j];
            }
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            int u = par[(i - 1) * m + j];
            for (int dir = 0; dir < 4; ++dir){
                int new_i = i + dx[dir];
                int new_j = j + dy[dir];
                if (!isCell(new_i, new_j)) continue;
                int v = par[(new_i - 1) * m + new_j];
                if (u == v){
                    continue;
                }
                long long w = cnt[v] * val[v];
                if (val[v] == 1) w = 0;
                adj[u].push_back({w, v});
                w = cnt[u] * val[u];
                if (val[u] == 1) w = 0;
                adj[v].push_back({w, u});
            }
        }
    }
}
void Solve(){
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i){
        par[i] = i;
    }
    FOR(i, 1, n)
        FOR(j, 1, m) cin >> a[i][j];
    Pre_Compute();
    priority_queue <ii, vector <ii>, greater <ii> > q;
    q.push({0, 1});
    FOR(i, 1, m * n) d[i] = +oo;
    d[1] = 0;
//    FOR(i, 1, n){
//        FOR(j, 1, m){
//            cout << par[(i - 1) * m + j] << ' ';
//        }
//        cout << endl;
//    }
    while (!q.empty()){
        int u = q.top().second;
        int du = q.top().first;
        vis[u] = true;
        q.pop();
        if (d[u] != du) continue;
        for (auto alpha : adj[u]){
            int v = alpha.second;
            int uv = alpha.first;
            if (vis[v]) continue;
            if (d[v] > d[u] + uv){
                d[v] = d[u] + uv;
                q.push({d[v], v});
            }
        }
    }
    cout << d[par[m * n]] << endl;
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
}
