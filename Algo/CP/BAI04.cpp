#include <bits/stdc++.h>
using namespace std;


#define TASK "BAI04"
#define X first
#define Y second

typedef pair <int, int> ii;

bool cut(ii x, ii y){
    return (x.first < y.first && x.second > y.second
            || x.first > x.first && x.second < y.second);
}
void Solve(){
    int n; cin >> n;
    vector <ii> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            ans += cut(a[i], a[j]);
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
