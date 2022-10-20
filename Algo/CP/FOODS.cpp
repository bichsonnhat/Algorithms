#include <bits/stdc++.h>
using namespace std;


#define TASK "FOODS"
#define X first
#define Y second
const int N = 1e5 + 5;
#define int long long
typedef pair <int, int> ii;
int n, m, low[N], num[N], time_DFS, scc, p[N], deg[N];
vector <int> adj[N], a[N];
int mask[N];
stack <int> s;
int ans, an, sum[N], res[N];
bool vis[N];

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
        while (v != u){
            v = s.top();
            s.pop();
            mask[v] = scc;
            sum[scc] += p[v];
        }
    }
}

void dfs(int u){
    vis[u] = true;
    for (auto v : a[u]){
        if (!vis[v]){
            ans += sum[v];
            an = max(an, ans);
            dfs(v);
            vis[v] = false;
            ans -= sum[v];
        }
    }
}

//void reset(int u){
//    vis[u] = false;
//    for (auto v : a[u]){
//        if (vis[v]){
//            reset(v);
//        }
//    }
//}
void Solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    while (m --> 0){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i]) DFS(i);
    for (int u = 1; u <= n; ++u){
        for (auto v : adj[u]){
            if (mask[v] != mask[u]){
                a[mask[v]].push_back(mask[u]);
                deg[mask[u]]++;
            }
        }
    }
    queue <int> q;
    for (int i = 1; i <= scc; ++i){
        if (deg[i] == 0){
            q.push(i);
            res[i] = sum[i];
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : a[u]){
            deg[v]--;
            res[v] = max(res[v], res[u] + sum[v]);
            if (deg[v] == 0){
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << res[mask[i]] << ' ';
    }
}
main(){
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
