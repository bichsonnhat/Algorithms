#include <bits/stdc++.h>
using namespace std;


#define TASK "BAI03"
#define X first
#define Y second

const int N = 1e6 + 5;
int sum_mod[N], sum = 0;
map <int, int> inv_mod;
void Solve(){
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        sum_mod[i] = ((sum % k) + k) % k;
    }
    int len = 0, l = 0, r = 0;
    for (int i = 0; i < n; ++i){
        if (!sum_mod[i]){ /// sum [1..i] % k = 0;
            l = 1;
            r = i + 1;
            len = r;
        } else
            if (inv_mod.find(sum_mod[i]) == inv_mod.end()) /// not find
                inv_mod[sum_mod[i]] = i;
            else {
                /// update ans;
                int new_l = inv_mod[sum_mod[i]] + 1;
                int new_r = i + 1;
                if (len < new_r - new_l + 1){
                    len = new_r - new_l + 1;
                    l = new_l;
                    r = new_r;
                }
            }
    }
    if (!len) {
        cout << 0 << '\n';
        return;
    }
    cout << l << ' ' << r << '\n';
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
