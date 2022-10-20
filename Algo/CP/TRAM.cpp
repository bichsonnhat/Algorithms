#include <bits/stdc++.h>
using namespace std;


#define TASK "TRAM"
#define X first
#define Y second

const int N = 1e5 + 5;
int n, m, a[N], ans = 0;
vector <int> adj[N];
typedef pair <int, int> ii;
map <pair<int, int> , bool> mp;
int par[N];
bool vis[N];
int d[N];
const int oo = 1e9;

void get(int s){
    queue <int> q;
    d[s] = 0;
    q.push(s);
    vis[s] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (!vis[v]) {
                d[v] = d[u] + 1;
                par[v] = u;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
void Calc(int x, int y) {
    int t1 = x;
    int t2 = y;
    while (d[t1] > d[t2]) {
        mp[{t1, par[t1]}] = 1;
        t1 = par[t1];
    }
    while (d[t1] < d[t2]) {
        mp[{t2, par[t2]}] = 1;
        t2 = par[t2];
    }
    while (t1 != t2) {
        mp[t1 * N + par[t1]] = 1;
        mp[t2 * N + par[t2]] = 1;
        t1 = par[t1];
        t2 = par[t2];
    }
}
void Solve(){
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 1;
    get(1);
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        Calc(u, v);
    }
    ans = n - 1;
    for (int i = 1; i <= n; i++)
        for (auto v : adj[i]) {
            ans -= mp[i * N + v];
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
