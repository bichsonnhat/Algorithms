#include <bits/stdc++.h>
using namespace std;


#define TASK "CENCITY"
#define X first
#define Y second
const int N = 1e5 + 5;
typedef pair <int, int> ii;
int n, m, low[N], num[N], time_DFS, scc;
vector <int> adj[N], a[N];
int mask[N], cand[N];
stack <int> s;

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
        }
    }
}

bool vis[N];

void reset(int u){
    vis[u] = false;
    for (auto v : a[u]){
        if (vis[v]){
            reset(v);
        }
    }
}
void dfs(int u){
    vis[u] = true;
    cand[u]++;
    for (auto v : a[u]){
        if (!vis[v]){
            dfs(v);
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
    for (int u = 1; u <= n; ++u){
        for (auto v : adj[u]){
            if (mask[u] != mask[v]){
                a[mask[u]].push_back(mask[v]);
            }
        }
    }
    for (int i = 1; i <= scc; ++i){
        dfs(i);
        reset(i);
    }
    vector <int> ans;
    for (int i = 1; i <= n; ++i){
        if (cand[mask[i]] >= scc){
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << (int) (ans.size()) << '\n';
    for (auto city : ans) cout << city << ' ';
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
