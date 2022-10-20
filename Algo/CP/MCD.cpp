#include <bits/stdc++.h>
using namespace std;


#define TASK "MCD"
#define X first
#define Y second

unordered_map <int, int> cnt;
int f(int n){
    int res = 0;
    while (n){
        res += n % 10;
        n /= 10;
    }
    return res;
}
void Solve(){
    int a, b; cin >> a >> b;
    for (int i = 1; i * i <= a; ++i){
        if (a % i == 0){
            ++cnt[i];
            if (i * i != a){
                ++cnt[a / i];
            }
        }
    }
    for (int i = 1; i * i <= b; ++i){
        if (b % i == 0){
            ++cnt[i];
            if (i * i != b){
                ++cnt[b / i];
            }
        }
    }
    int ans = 0;
    for (auto x : cnt){
        if (x.second == 2){
            ans = max(ans, f(x.first));
        }
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
