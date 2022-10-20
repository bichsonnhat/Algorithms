#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int oo = 1e8;
const int N = 3e4 + 5;

vector <ii> adj[N];
int d[N], trace[N], xe[N], n, m, x, y, w, cnt, dem;
bool check[N];
int ch[N];
set <int> se[N];
vector <int> res[N];
vector <int> di;

void dijkstra(int s) {
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    for (int i = 2; i <= n; i++)
        d[i] = oo;
    d[1] = 0;
    pq.push({0, 1});
    trace[1] = 1;
    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (auto z : adj[u]) {
            int v = z.second;
            int dv = z.first;
            if (d[v] > d[u] + dv) {
                d[v] = d[u] + dv;
                se[v].clear();
                se[v].insert(u);
                trace[v] = u;
                pq.push({d[v], v});
            }
                else if (d[v] == d[u] + dv) {
                    se[v].insert(u);
                }
        }
    }
}

void xuat(int i) {
    cnt++;
    for (int j = 1; j <= i; j++) {
        if (ch[xe[j]] == 0)
            di.push_back(xe[j]);
        ch[xe[j]]++;
    }
}

void Try(int u, int i) {
    for (auto v : se[u]) {
        xe[i] = v;
        if (trace[v] == v) xuat(i);
            else Try(v, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    freopen("CENTRE.INP","r",stdin);
    freopen("CENTRE.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
    dijkstra(1);
    m = n;
    cnt = 0;
    xe[1] = m;
    Try(m, 2);
    dem = 0;
    for (int i = 0; i < di.size(); i++)
        if (ch[di[i]] == cnt) {
            dem++;
            check[di[i]] = 1;
        }
    cout << n - dem << endl;
    for (int i = 1; i <= n; i++)
        if (!check[i]) cout << i << endl;
}
