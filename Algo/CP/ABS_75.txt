#include <bits/stdc++.h>
using namespace std;


#define TASK "ABS"
#define X first
#define Y second
#define int long long
const int N = 200;
int ans = 0, n, k, a[25], cnt = 0, mem[N][N];
char s[N];
bool ok;
void Solve(){
    int A = 0, B = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] == 1) ++B;
            else ++A;
    }
    if (B > A) ++cnt;
    if (cnt == k) {
        for (int i = 1; i <= n; ++i)
            if (a[i] == 0) cout << "A";
                else cout << "B";
        cout << '\n';
        ok = 1;
    }
}
void Try(int i){
    if (ok) return;
    for (int j = 0; j < 2; ++j){
        a[i] = j;
        if (i == n) Solve();
            else Try(i + 1);
    }
}
void Subtask_1(){
    cnt = 0, ok = 0;
    Try(1);
    if (!cnt || (k > cnt)) cout << "-1\n";
}

int dp(int i, int c){
    if (i > n) {
        mem[i][c] = (2 * c < n);
        return mem[i][c];
    }
    int &res = mem[i][c];
    if (res == -1)
        mem[i][c] = dp(i + 1, c + 1) + dp(i + 1, c);
    return mem[i][c];
}

void f(int i, int c){
    if (i > n) return;
    if (k <= mem[i + 1][c + 1]) {
        s[i] = 'A';
        f(i + 1, c + 1);
    } else {
        s[i] = 'B';
        k -= mem[i + 1][c + 1];
        f(i + 1, c);
    }
}
 main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    while (cin >> n >> k){
        memset(mem, -1, sizeof(mem));
        int cnt = dp(1, 0);
        if (k > cnt){
            cout << "-1\n";
            continue;
        }
        f(1, 0);
        for (int i = 1; i <= n; ++i)
            cout << s[i];
        cout << '\n';
    }
}
