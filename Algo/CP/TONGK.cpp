#include <bits/stdc++.h>
using namespace std;

#define TASK "TONGK"

void Solve(){
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (auto &x : a) cin >> x;
    int res = 0;
    vector <pair <int, int> > ans;
    for (int i = 0; i < n; ++i){
        int sum = a[i];
        if (sum == k){
            ans.push_back({i, i});
        }
        for (int j = i + 1; j < n; ++j){
            sum += a[j];
            if (sum == k){
                ans.push_back({i, j});
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &x : ans){
        cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }
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
}
