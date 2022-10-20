#include <bits/stdc++.h>
using namespace std;


#define TASK "FT"
#define X first
#define Y second

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 5e3 + 5;
const int oo = 1e9;
int n, m, k = 1;
vector <ii> adj[N];
int d[N][2];
void Solve(){
    cin >> n >> m;
    while (m--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    priority_queue <iii, vector <iii>, greater <iii> > q;
    q.push({0, {1, 0}});
    for (int i = 0; i <= k; ++i){
        for (int j = 1; j <= n; ++j){
            d[j][i] = +oo;
        }
    }
    d[1][0] = 0;
    while (!q.empty()){
        int u = q.top().second.first;
        int du = q.top().first;
        int i = q.top().second.second;
        q.pop();
        if (du != d[u][i]) continue;
        for (auto alpha : adj[u]){
            int v = alpha.second;
            int uv = alpha.first;
            if (d[v][i] > d[u][i] + uv){
                d[v][i] = d[u][i] + uv;
                q.push({d[v][i], {v, i}});
            }
            if (i < k) {
                if (d[v][i + 1] > d[u][i]){
                    d[v][i + 1] = d[u][i];
                    q.push({d[v][i + 1], {v, i + 1}});
                }
            }
        }
    }
    cout << d[n][k] << '\n';
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
