#include <bits/stdc++.h>

using namespace std;

int n;
int sum;
int ans[100];

void print(int i) {
    for (int j = 1; j <= i; ++j){
        if (j == i){
            cout << ans[j] << '\n';
        } else cout << ans[j] << "+";
    }
}

void gen(int i, int k) {
    for (int j = k; j <= n; j++) {
        if (sum + j > n) return;
        ans[i] = j;
        sum += j;
        if (sum < n) gen(i + 1, j);
            else print(i);
        sum -= j;
    }
}

int main() {
    ios::sync_with_stdio(0);
    freopen("PTSO.INP","r",stdin);
    freopen("PTSO.OUT","w",stdout);
    cin >> n;
    gen(1, 1);
}
