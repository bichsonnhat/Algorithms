#include <bits/stdc++.h>
using namespace std;


#define TASK "ISLAND"
#define X first
#define Y second

typedef pair <int, int> ii;
const int N = 1e3 + 5;
bool vis[N][N];
int a[N][N], n, m;
ii q[110];
int ans[110];
const int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
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

bool isCell(int r, int c){
    return (r >= 1 && r <= n && c >= 1 && c <= m);
}
void Solve(){
    cin >> n >> m;
//    DSU dsu(m * n);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }
    int t; cin >> t;
    int prev = -1, land = 0, h;
    for (int alpha = 1; alpha <= t; ++alpha){
        cin >> h;
        if (h == prev) {
            cout << land << ' ';
            continue;
        }
        prev = h;
        land = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (a[i][j] <= h || vis[i][j]) {
                    continue;
                }
                ++land;
                queue <ii> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty()){
                    int u = q.front().first;
                    int v = q.front().second;
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir){
                        int r = (u + dx[dir]);
                        int c = (v + dy[dir]);
                        if (isCell(r, c)){
                            if (a[r][c] > h && !vis[r][c]){
                                vis[r][c] = true;
                                q.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        cout << land << ' ';
    }
//    for (int i = 1; i <= t; ++i){
//        cout << ans[i] << ' ';
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
    while (ntests--)
        Solve();
    return 0;
}
