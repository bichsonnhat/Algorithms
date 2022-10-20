#include <bits/stdc++.h>
using namespace std;


#define TASK "MULT"
#define X first
#define Y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int t;
    cin >> t;
    while (t --> 0){
        long long n, x;
        cin >> n >> x;
        cout << x / n << '\n';
    }
    return 0;
}
