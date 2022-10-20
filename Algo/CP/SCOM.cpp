#include <bits/stdc++.h>
using namespace std;


#define TASK "SCOM"
#define X first
#define Y second
const int N = 1e5 + 5;
typedef pair <int, int> ii;
int n, m, low[N], num[N], time_DFS, scc;
vector <int> adj[N];
stack <int> s;
int res[N];
bool vis[N];
int mask[N];
bool f[N];
int ans;

struct DSU {
    vector<int> par;
    DSU() {};
    DSU(int n) {
        par.resize(n + 5);
        for (int u = 1; u <= n; u++)
            par[u] = u;
    }
    int get_root(int u) {
        if (par[u] == u) return u;
        return (par[u] = get_root(par[u]));
    };
    void join(int u, int v) {
        par[get_root(v)] = get_root(u);
    };
    bool diff(int u, int v) {
        return get_root(u) != get_root(v);
    };
};

void dfs_similar(int u){
    vis[u] = true;
    for (auto v : adj[u]){
        if (!vis[v] && !f[mask[v]]){
            if (mask[u] != mask[v]) {
                f[mask[v]] = true;
                ans--;
            }
            dfs_similar(v);
        }
    }
}

void reset(int u) {
    vis[u] = 0;
    for (auto v : adj[u]) {
        if (vis[v])
            reset(v);
    }
}

void DFS(int u){
    low[u] = num[u] = ++time_DFS;
    s.push(u);
    for (auto v : adj[u]){
        if (mask[v]) continue;
        if (!num[v]){
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]){
        ++scc;
        int v;
        res[scc] = u;
        while (v != u){
            v = s.top();
            s.pop();
            mask[v] = scc;
//            res[scc].push_back(v);
        }
    }
}
void Solve(){
    cin >> n >> m;
    while (m --> 0){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i]) DFS(i);
    ans = scc;
    for (int i = 1; i <= scc; ++i){
        if (f[i]) continue;
        int u = res[i];
        dfs_similar(u);
//        memset(vis, 0, sizeof(vis));
        reset(u);
    }
    cout << ans << '\n';
//    set <int> s;
//    for (int i = 1; i <= scc; ++i){
//        s.insert(dsu.par[i]);
//    }
//    cout << (int)(s.size()) << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int ntests = 1;
//    cin >> ntests;
    while (ntests--) Solve();
    return 0;
}
