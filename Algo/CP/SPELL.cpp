#include <bits/stdc++.h>
using namespace std;


#define TASK "SPELL"
#define X first
#define Y second
const int N = 3e2 + 5;
const int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int oo = 1e9;
typedef pair <int, int> ii;
typedef pair <int, pair <int, int> > iii;
char a[N][N];
int n, m, k, ans, x, y;
bool f[1000005];
vector <ii> pos[30];
vector <ii> v;
string s;


void Calc_1(){
    string new_s = "";
    int sum = 0;
    for (int i = 0; i < v.size(); ++i){
        if (f[i + 1]) {
            int r = v[i].first;
            int c = v[i].second;
            new_s += a[r][c];
            int cost = abs(r - x) + abs(c - y);
            sum += cost;
            swap(x, r);
            swap(y, c);
        }
    }
    if (new_s == s) ans = min(ans, sum);
}
void Try(int i){
    for (int j = 0; j < 2; ++j){
        f[i] = j;
        if (i == (int)(v.size())) Calc_1();
            else Try(i + 1);
    }
}

void Subtask_1(){
    for (int i = 0; i < k; ++i){
        for (auto p : pos[s[i] - 'A']){
            v.push_back({p.first, p.second});
        }
    }
    ans = +oo;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int x = i, y = j;
            Try(1);
        }
    }
    cout << ans << '\n';
}
void Solve(){
    cin >> n >> m >> k;
    cin >> s;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            pos[a[i][j] - 'A'].push_back({i, j});
        }
    if (n <= 4 && m <= 4 && k <= 4) {
        Subtask_1();
        return;
    }
    cout << rand();
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
