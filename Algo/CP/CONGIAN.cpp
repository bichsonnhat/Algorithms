#include <bits/stdc++.h>
using namespace std;


#define TASK "TASK"
#define X first
#define Y second
typedef pair <int, int> ii;
const int N = 1e4 + 5;
const int oo = 1e9;
vector <ii> adj[N];
int n, m, d[N];
int Prim(int s){
    priority_queue <ii, vector <ii>, greater <ii> > pq;
    for (int i = 1; i <= n; ++i)
        d[i] = +oo;
    d[s] = 0;
    int ans = 0;
    pq.push({0, s});
    while (!pq.empty()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        ans += d[u];
        d[u] = -oo;
        for (auto x : adj[u]){
            int v = x.second;
            int uv = x.first;
            if (d[v] > uv){
                d[v] = uv;
                pq.push({d[v], v});
            }
        }
    }
    return ans;
}
void Solve(){
    cin >> n >> m;
    while (m --> 0){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    cout << Prim(1);
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
