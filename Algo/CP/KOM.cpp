#include <bits/stdc++.h>
using namespace std;


#define TASK "KOM"
#define X first
#define Y second

const int N = 3e4 + 5;
int n, m, a[N], ans = 0;
vector <int> adj[N];
typedef pair <int, int> ii;
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
        ans++;
        t1 = par[t1];
    }
    while (d[t1] < d[t2]) {
        ans++;
        t2 = par[t2];
    }
    while (t1 != t2) {
        ans += 2;
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
        cin >> a[i];
        if (i == 1) continue;
        Calc(a[i - 1], a[i]);
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
