#include <bits/stdc++.h>
using namespace std;


#define TASK "TREAT"
#define X first
#define Y second
const int N = 1e5 + 5;
typedef pair <int, int> ii;
int n, m, low[N], num[N], time_DFS, scc;
vector <int> adj[N], a[N];
int mask[N];
stack <int> s;
int sum[N], r;
bool k[N], ok;
vector <int> p;
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
        int v, cnt = 0;
        while (v != u){
            v = s.top();
            s.pop();
            mask[v] = scc;
            ++cnt;
        }
        if (cnt > 1 || (cnt == 1 && k[u]))
            sum[scc] = cnt;
    }
}

void dfs(int u){
    if (!ok) r++;
//    cout << r << '\n';
    for (auto v : adj[u]){
        if (sum[mask[v]]) {
            ok = true;
            r += sum[mask[v]];
            return;
        }
            else dfs(v);
        if (ok) return;
    }
}
void Solve(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int nxt_i; cin >> nxt_i;
        adj[i].push_back(nxt_i);
        if (i == nxt_i){
            k[i] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i]) DFS(i);
    for (int i = 1; i <= n; ++i){
        if (k[i]){
            cout << 1 << '\n';
            continue;
        }
        if (sum[mask[i]] > 1){
            cout << sum[mask[i]] << '\n';
            continue;
        }
        r = 0;
        ok = false;
        dfs(i);
        cout << r << endl;
    }
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
