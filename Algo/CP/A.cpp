#include <bits/stdc++.h>
using namespace std;


#define TASK "TASK"
#define X first
#define Y second

const int N = 3e5 + 5;

int f(vector <int> v, int k){
    int l = 0, r = v.size() - 1, ans = -1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (v[mid] <= k){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}
void Solve(){
    int n, k;
    cin >> n >> k;
    vector <int> sz[25];
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int m = s.size();
        sz[m].push_back(i);
    }
    int ans = 0;
    for (int len = 1; len <= 20; ++len){
        if (sz[len].size() <= 1) continue;
        for (int i = 0; i < sz[len].size(); ++i){
            int pos = sz[len][i];
            int new_pos = f(sz[len], pos + k);
//            cerr << pos << ' ' << new_pos << '\n';
            if (new_pos != -1) ans += (new_pos - i);
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
    int ntests = 1;
//    cin >> ntests;
    while (ntests--) Solve();
    return 0;
}
