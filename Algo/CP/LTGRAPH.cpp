#include <bits/stdc++.h>
using namespace std;


#define TASK "LTGRAPH"
#define X first
#define Y second
const int MOD = 998244353;
const int N = 3e5 + 5;

vector <int> adj[N];
vector <int> cc[N];
int num_cc = 0;
bool vis[N];
long long ans = 1;

long long fpow(int x, int y){
    long long t;
    if (y == 0) return 1;
    t = fpow(x, y / 2) % MOD;
    if (y % 2) return 1LL * x * t % MOD * t % MOD;
        else return t * t % MOD;
}
void DFS(int u){
    if (!vis[u]) {
        cc[num_cc].push_back(u);
        vis[u] = true;
    }
    for (auto v : adj[u]){
        if (!vis[v]){
            DFS(v);
        }
    }
}
void Solve(){
    int n, m; cin >> n >> m;
    while (m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
        if (!vis[i]) {
            ++num_cc;
            DFS(i);
            int a = 0, b = 0;
            for (auto alpha : cc[num_cc]){
                a += (alpha % 2);
                b += (alpha % 2 == 0);
            }
            a = fpow(2, a) % MOD;
            b = fpow(2, b) % MOD;
            long long curr = (a + b) % MOD;
            ans = 1LL * ans * curr % MOD;
            while (ans < 0) ans += MOD;
        }
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
    return 0;
}
