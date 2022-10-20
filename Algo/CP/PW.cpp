#include <bits/stdc++.h>
using namespace std;


#define TASK "PW"
#define X first
#define Y second

struct Safe{
    int lo, hi, num;
};

void Solve(){
    string s; cin >> s;
    int n = (int) (s.size());
    s = "#" + s;
    vector <Safe> pref(n + 1);
    pref[0].lo = pref[0].hi = pref[0].num = 0;
    for (int i = 1; i <= n; ++i){
        pref[i].lo = pref[i - 1].lo + ('a' <= s[i] && s[i] <= 'z');
        pref[i].hi = pref[i - 1].hi + ('A' <= s[i] && s[i] <= 'Z');
        pref[i].num = pref[i - 1].num + ('0' <= s[i] && s[i] <= '9');
    }
    long long ans = 0;
    auto f = [&](int curr_pos) -> int{
        int l = curr_pos + 5, r = n, res = -1;
        while (l <= r){
            int mid = (l + r) >> 1;
            int cand = 0;
            cand += (pref[mid].lo - pref[curr_pos - 1].lo > 0)
                   + (pref[mid].hi - pref[curr_pos - 1].hi > 0)
                   + (pref[mid].num - pref[curr_pos - 1].num > 0);
            if (cand >= 3){
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    };
    for (int i = 1; i <= (n - 5); ++i){
        int pos = f(i);
        if (pos != -1){
            ans += (n - pos + 1);
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
