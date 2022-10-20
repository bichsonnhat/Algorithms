#include <bits/stdc++.h>
using namespace std;


#define TASK "LENAB"
#define X first
#define Y second

void Solve(){
    int countA, countB, maxA, maxB;
    cin >> countA >> countB >> maxA >> maxB;
    if (!maxA) countA = 0;
    if (!maxB) countB = 0;
    if (countA > countB) swap(countA, countB), swap(maxA, maxB);
    cout << countA + min((long long)countB, 1LL * (countA + 1) * maxB) << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int t;
    cin >> t;
    while (t--){
        Solve();
    }
}
