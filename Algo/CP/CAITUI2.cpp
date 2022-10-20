#include <bits/stdc++.h>
#define rep(i, a, b)   for(int i = a; i <= b; ++i)
#define repr(i,a,b)    for(int i = a ; i >= b; --i)
#define NAME           "NAME"
#define pb             push_back
#define mp             make_pair
#define EL             cout << '\n'
#define cqtshadow      int main
#define fillchar(a,x)  memset(a, x, sizeof (a))
#define faster         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef int64_t        ll;
typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef pair<int, int> ii;
typedef pair<ll, ll>   iil;
const ll  oo  =  1e18;
const int inf =  1e9;
const int mod =  1e9 + 7;
const int N   =  1e5 + 7;
const int M   =  1e4 + 7;
void file() {freopen ( NAME ".inp", "r", stdin ); freopen ( NAME ".out", "w", stdout ); freopen ( NAME ".err", "w", stderr);}

int n, m, dp[M], res;
vector<ii> W[M];

cqtshadow () {
	faster
	cin >> n >> m;
	int x, y, z;
	rep(i, 1, n) {
		cin >> x >> y >> z;
		W[x].pb({y,z});
	}
	rep(i, 1, m) sort(W[i].begin(), W[i].end(), greater<ii>());
	rep(i, 1, m) {
		int cnt = 0, limit = m/i, siz = W[i].size();
		for(int sl = 1 ; sl <= limit && cnt < siz ; ++sl, cnt += (W[i][cnt].second == 0)) {
			repr(k, m, i)  {
				dp[k] = max(dp[k], dp[k - i] + W[i][cnt].first);
				res = max(res, dp[k]);
			}
			W[i][cnt].second--;
		}
	}
	cout << res;
}
