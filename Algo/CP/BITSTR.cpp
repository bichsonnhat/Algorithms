#include <bits/stdc++.h>
using namespace std;


#define TASK "BITSTR"
#define X first
#define Y second

const int N = 2e5 + 5;
string s;
int n, k, d[N], change;
bool x[N];
int Count_Substr(string s){
    int len = s.size(), cnt = 0;
    s = s + "#";
    for (int i = 0; i <= len; ++i){
        if (s[i] == s[i + 1]) continue;
            else ++cnt;
    }
    return cnt - 1;
}

void Calc(){
    string t = s;
    int cnt = 0;
//    for (int i = 1; i <= n; ++i)
//        cout << x[i];
//    cout << '\n'; return;
    for (int i = 0; i < n; ++i){
        if (x[i + 1]){
            ++cnt;
            if (t[i] == '0') {
                t[i] = '1';
                continue;
            }
            t[i] = '0';
        }
    }
    d[cnt] += (Count_Substr(t) <= k);
}

void Try(int i){
    for (int j = 0; j < 2; ++j){
        x[i] = j;
        if (i == n) Calc();
            else Try(i + 1);
    }
}
void Subtask_1(){
    d[0] = (Count_Substr(s) <= k);
    Try(1);
    for (int i = 0; i <= n; ++i){
        if (d[i] > 0){
            cout << i;
            return;
        }
    };
}
void Solve(){
    cin >> n >> k;
    cin >> s;
    if (n <= 20){
        Subtask_1();
        return;
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
    while (ntests--) Solve();
    return 0;
}
