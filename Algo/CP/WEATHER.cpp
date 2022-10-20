#include <bits/stdc++.h>
using namespace std;


#define TASK "WEATHER"
#define X first
#define Y second

const int N = 1e2 + 5;
vector <int> adj[N];
int n, m, low[N], num[N], time_DFS;
int bridge;
bool joint[N];
vector <pair <int, int> > br;
int cnt = 0;
bool vis[N];
bool check[N][N];

void dfs(int u, int t){
    ++cnt;
    vis[u] = true;
    for (auto v : adj[u]){
        if (!vis[v] && v != t) dfs(v, t);
    }
}

void reset(int u, int t){
    vis[u] = false;
    for (auto v : adj[u]){
        if (vis[v] && v != t) reset(v, t);
    }
}
void DFS(int u, int par){
    int child = 0;
    low[u] = num[u] = ++time_DFS;
    for (auto v : adj[u]){
        if (v == par) continue;
        if (!num[v]){
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            ++child;
            bridge += (low[v] == num[v]);
            if (low[v] == num[v]){
                br.push_back({u, v});
            }
            if (u == par){
                if (child > 1) joint[u] = true;
            } else if (low[v] >= num[u]) joint[u] = true;
        } else low[u] = min(low[u], num[v]);
    }
}
void Solve(){
    cin >> n >> m;
    while (m --> 0){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i]) DFS(i, i);
    int ans = 0;
    int res = 0;
    for (auto alpha : br){
        cnt = 0;
        dfs(alpha.first, alpha.second);
        reset(alpha.first, alpha.second);
//        res = cnt;
//        cnt = 0;
//        dfs(alpha.second, alpha.first);
//        reset(alpha.second, alpha.first);
//        res *= cnt;
        ans += cnt * (n - cnt);
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
    int ntests = 1;
//    cin >> ntests;
    while (ntests--)
        Solve();
    return 0;
}
