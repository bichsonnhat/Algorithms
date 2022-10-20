#include <bits/stdc++.h>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define TASK "EQUA"
#define X first
#define Y second
const int N = 1e6;

int comp[N + 5], cnt[N + 5];
vector <int> p;
vector <pair <int, int> > f[N + 5];

void Prepare(){
    for (int i = 2; i <= N; ++i){
        int a = i;
        while (a != 1){
            int t = comp[a], cnt = 0;
            while (a % t == 0){
                a /= t;
                ++cnt;
            }
            f[i].push_back({t, cnt});
        }
    }
}
void Solve(){
    int a, b;
    cin >> a >> b;
    long long ans = 1;
    for (auto x : f[a]){
        cnt[x.first] += x.second;
    }
    for (auto x : f[b]){
        if (cnt[x.first]){
            cnt[x.first] += x.second;
            ans = 1LL * ans * (2 * cnt[x.first] + 1);
            cnt[x.first] = 0;
        } else {
            ans *= 3;
        }
    }
    for (auto x : f[a]){
        if (cnt[x.first]) ans *= 3, cnt[x.first] = 0;
    }
    cout << ans << '\n';

//    long long ans = 1;
//    for (auto x : f[a]){
//        cnt[x.first] += x.second;
//    }
//    for (auto x : f[b]){
//        cnt[x.first] += x.second;
//    }
//    cout << ans << '\n';
}

void Brute(){
    int a, b;
    cin >> a >> b;
    unordered_map <int, int> cnt;
    long long ans = 1;
    for (int i = 2; i * i <= a; ++i){
        if (a % i == 0){
            int count = 0;
            while (a % i == 0){
                ++count;
                a /= i;
            }
            cnt[i] += count;
        }
    }
    if (a > 1) cnt[a]++;
    for (int i = 2; i * i <= b; ++i){
        if (b % i == 0){
            int count = 0;
            while (b % i == 0){
                ++count;
                b /= i;
            }
            cnt[i] += count;
        }
    }
    if (b > 1) cnt[b]++;
    for (auto val : cnt){
        ans = 1LL * ans * (2 * val.second + 1);
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int ntests = 1;
    for (int i = 2; i <= N; ++i){
        if (!comp[i]) p.push_back(i), comp[i] = i;
        for (int j = 0; j < p.size() && p[j] * i <= N; ++j){
            comp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
    cin >> ntests;
    if (ntests <= 100) {
        while (ntests--){
            Brute();
        }
    } else {
        Prepare();
        while (ntests--){
            Solve();
        }
    }
    return 0;
}
