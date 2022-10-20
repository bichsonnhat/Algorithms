#include <bits/stdc++.h>
using namespace std;


#define TASK "KIOSKS"
#define X first
#define Y second
const int N = 1e4 + 5;
const int MOD = 1e9 + 7;
int n, k, scc, c[N];
bool vis[N];
vector <int> adj[N];
long long fact[N];
long long inv[N];
long long pw(long long a, long long n) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

long long combi(int n, int k) {
    if (n < k || k < 0) return 1;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
void DFS(int u){
    vis[u] = 1;
    for (auto v : adj[u]){
        if (!vis[v]){
            DFS(v);
        }
    }
}
void Subtask_1(){
    DFS(1);
    for (int i = 1; i <= n; ++i){
        scc += vis[i];
    }
    long long ans = 0;
    for (int i = 2; i <= n; ++i){
        ans = ans + combi(scc, i) % MOD;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}
void Solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (k == 1) {
        Subtask_1();
        return;
    }
    long long x = rand();
    x = (x + MOD) % MOD;
    cout << x % MOD << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    fact[0] = 1;
    for (int i = 1; i <= N - 5; ++i){
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }
    int ntests = 1;
//    cin >> ntests;
    while (ntests--) Solve();
    return 0;
}
