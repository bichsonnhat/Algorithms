#include <bits/stdc++.h>
using namespace std;


#define TASK "LABLE"
#define X first
#define Y second
const int N = 4e5 + 5;
typedef pair <int, int> ii;
int n, m, low[N], num[N], time_DFS, scc;
vector <int> adj[N];
int mask[N];
stack <int> s;
vector <int> a[N];
int ans[N];
bool k[N], check[N], visit[N], seen[N];

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
        if (s.top() == u && k[u] == true){
            check[scc] = true;
        }
        int cnt = 0;
        while (v != u){
            v = s.top();
            s.pop();
            mask[v] = scc;
            ++cnt;
        }
        if (cnt > 1) check[scc] = true;
    }
}

void dfs(int u, int p){
    if (check[u] || ans[p] == -1) ans[u] = -1;
        else ans[u] = 1;
    visit[u] = true;
    for (auto v : a[u]){
        if (!visit[v]){
            dfs(v, u);
        } else if (ans[v] != -1) ans[v] = 2;
    }
}

void reset(int u){
    seen[u] = false;
    for (auto v : a[u]){
        if (seen[v]){
            reset(v);
        }
    }
}
void dfs_similar(int u){
    if (ans[u] != -1){
        ans[u] = 2;
    }
    seen[u] = true;
    for (auto v : a[u]){
        if (!seen[v]){
            dfs_similar(v);
        }
    }
}
void Solve(){
    cin >> n >> m;
    while (m --> 0){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if (u == v) k[u] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i]) DFS(i);
    for (int i = 1; i <= n; ++i){
        for (auto x : adj[i]){
            if (mask[i] != mask[x]){
                a[mask[i]].push_back(mask[x]);
            }
        }
    }
    dfs(mask[1], mask[1]);
    for (int i = 1; i <= scc; ++i){
        if (ans[i] == 2){
            dfs_similar(i);
            reset(i);
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << ans[mask[i]] << ' ';
    }
//    for (int i = 1; i <= n; ++i){
//        cout << i << ' ' << ' ' << mask[i] << ' ' <<ans[mask[i]] << '\n';
//    }
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
