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
const ll N = 5e5 + 5;
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

int n, k;
string s;
char ch[30];
long long ans = 0;
int x[20], cnt_a = 0;
void Init(){
    for (char i = 'a'; i <= 'z'; ++i){
        ch[(i - 'a' + 1)] = i;
    }
    for (int i = 0; i < n; ++i){
        cnt_a += (s[i] == 'a');
    }
}
bool isChoose(string a, string b){
    int len = (int) (a.size());
    int cnt = 0;
    for (int i = 0; i < len; ++i){
        string new_a = "", new_b = "";
        for (int j = i; j < len; ++j){
            new_a += a[j]; new_b += b[j];
            cnt += (new_a > new_b);
            if (cnt > k) return false;
        }
    }
    return (cnt == k);
}

void Calc(){
    /// Generate
    string t = "";
    for (int i = 1; i <= n; ++i){
        t += ch[x[i]];
    }
    if (isChoose(t, s)){
        ++ans;
//        cout << t << '\n';
    }
}
void Try(int i){
    for (int j = 1; j <= 26; ++j){
        x[i] = j;
        if (i == n){
            Calc();
        } else Try(i + 1);
    }
}
void Subtask_1(){
    Try(1);
    cout << ans << '\n';
}

void Subtask(){
    ans = 1;
    for (int i = 0; i < n; ++i){
        int val = 26 - (s[i] - 'a' + 1);
        ans = 1LL * ans * val % MOD;
        while (ans < 0) ans += MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

void Subtask_4(){
    ans = 1;
    for (int i = 0; i < n; ++i){
        int val = (s[i] - 'a' + 1);
        ans = ans * val % MOD;
        while (ans < 0) ans += MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

void Subtask_5(){
    cout << "0\n";
    return;
}

void Solve(){
    cin >> n >> k;
    cin >> s;
    Init();
    if (k == 0){ /// k = 0
        Subtask_4();
        return;
    }
    if (cnt_a == n){ /// all char = 'a'
        Subtask_5();
        return;
    }
    if (n <= 5) { /// n <= 5, generate O(26^n)
        Subtask_1();
        return;
    }
    Subtask();
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
