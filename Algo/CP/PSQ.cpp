#include <bits/stdc++.h>
using namespace std;


#define TASK "PSQ"
#define X first
#define Y second

const int N = 1e6;
bool g[N + 5];

void Sieve(){
    vector <int> p;
    g[1] = 1; g[0] = 1;
    for (int i = 2; i <= N; ++i){
        if (!g[i]) p.push_back(i);
        for (int j = 0; j < p.size() && p[j] * i <= N; ++j){
            g[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int n, m;
    cin >> n >> m;
    Sieve();
    int a[n + 5][m + 1], f[n + 5][m + 5];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            a[i][j] = 0, f[i][j] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            int x;
            cin >> x;
            if (!g[x]) a[i][j] = 1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 1) {
                f[i][j] = 0;
                continue;
            } else {
                f[i][j] = min({f[i-1][j], f[i][j-1], f[i-1][j-1]}) + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        res = max(res, *max_element(f[i]+1, f[i]+m+1));
    }
    cout << 1LL * res * res << endl;
}
