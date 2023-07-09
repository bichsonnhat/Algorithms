#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define ms(s, n) memset(s, n, sizeof(s))
#define sz(a) (int) ((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7; //998244353
const int oo = 1e9;
const int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll binPow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";

// WARNING: </test = 1>!"
void solve(){
  int n, w1, w2; cin >> n >> w1 >> w2;
  vector <int> a(n + 1);
  vector <vector <ll> > dp(n + 1, vector <ll> (6));
  for (int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= min(i, 5); ++j){
      ll w; 
      if (j == 1 || j == 5) w = 1LL * w1 * a[i];
      if (j == 2 || j == 4) w = 1LL * w2 * a[i];
      if (j == 3) w = a[i];
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + w);
    }
  }
  cout << dp[n][5] << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("TRAINING.INP","r",stdin);
    freopen("TRAINING.OUT","w",stdout);
  #endif
  int test = 1;
  // cin >> test; 
  while (test--){
    solve();
  }
  return 0;
}