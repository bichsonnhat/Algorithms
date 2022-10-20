#include <bits/stdc++.h>
using namespace std;


#define TASK "BAI02"
#define X first
#define Y second

const int N = 1e7;
bool comp[N + 5];
vector <int> primes;
int rev(int n){
    int ret = 0;
    while (n) ret = ret * 10 + (n % 10), n /= 10;
    return ret;
}
void Solve(){
    int L, R; cin >> L >> R;
    comp[1] = true; /// 1 is not prime;
    for (int i = 2; i <= N; ++i){
        if (!comp[i]) primes.push_back(i);
        for (int j = 0; j < (int) primes.size() && primes[j] * i <= N; ++j){
            comp[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    int ans = 0;
    for (int x = L; x <= R; ++x){
        ans += (!comp[x] && !comp[rev(x)]);
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
