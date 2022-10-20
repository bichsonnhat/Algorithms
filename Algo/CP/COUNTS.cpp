#include <bits/stdc++.h>
using namespace std;

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional>
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


#define TASK "COUNTS"
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
const ll N = 1e5 + 5;
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

pair <long long, int> pref[N];
long long S, bit[N];
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n;
int x;
//ordered_set <pair <long long, int> > s;
long long ans = 0;
void update(long long u) {
    for (long long x = u; x < N; x += x & -x) {
        bit[x]++;
    }
}
long long get(long long u) {
    long long res = 0;
    while (u > 0){
        res += bit[u];
        u -= u & -u;
    }
    return res;
}
void Solve(){
    cin >> n >> S;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        pref[i].first = pref[i - 1].first + (x - S);
        pref[i].second = i + 1;
    }
    pref[0].second = 1;
    sort(pref, pref + n + 1, [](pair <long long, int> x, pair <long long, int> y){
        if (x.first == y.first) return x.second < y.second;
            else return x.first > y.first;
    });
    long long ans = 0;
//    s.insert({0, 0});
    for (int i = 0; i <= n; ++i){
//        for (int x = pref[i].second; x >= 1; x -= x & -x)
//            ans += bit[x];
//        for (int x = pref[i].second; x <= n + 1; x += x & -x){
//            bit[x]++;
//        }
//        ans += s.order_of_key({pref[i].first, n + 1});
//        s.insert({-pref[i].first, i});
//        ans += s.order_of_key({pref[i].first, pref[i].second});
//        s.insert({pref[i].first, pref[i].second});
//        int val = lower_bound(pref, pref + n + 1, pref[i].second) - pref;
        ans += get(pref[i].second);
        update(pref[i].second);
//        cout << pref[i].first << ' ' << pref[i].second << '\n';
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
    int ntest = 1;
//    cin >> ntest;
    while (ntest--){
        Solve();
    }
}
