#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, k, m;
ii a[N];

bool cmp(ii x, ii y) {
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}

int main() {
    ios::sync_with_stdio(0);
//    freopen("DREAM.INP","r",stdin);
//    freopen("DREAM.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    int res = 0;
    sort(a + 1, a + 1 + n, cmp);
    int pos = 0;
    a[0].first = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i].first != a[i - 1].first) pos = 0;
        if (a[i].second <= pos) continue;
        pos = a[i].second + k - 1;
        res++;
    }
    cout << res;
}
