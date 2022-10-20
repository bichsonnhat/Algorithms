#include <bits/stdc++.h>
using namespace std;


#define TASK "TKNP"
#define X first
#define Y second

int f(vector <int> &a, int n, int k){
    int l = 0, r = n - 1, ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] == k){
            return mid + 1;
        }
        if (a[mid] < k){
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}
void Solve(){
    int n, q; cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (q--){
        int x; cin >> x;
        cout << f(a, n, x) << '\n';
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
    return 0;
}
