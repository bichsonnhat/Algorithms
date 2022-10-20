#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 5;
const int oo = 1e9;

int res = N;
int l, n;
int a[N], x[N];
//int dp[10005][35][35];
//int dp2[105][5005][105];
pair <int, int> dp3[10050][5050];

void check() {
    long long L = 0, R = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!x[i]) {
            L += a[i];
            if (L > l) {
                ans++;
                L = a[i];
            }
        }
            else {
                R += a[i];
                if (R > l) {
                    ans++;
                    R = a[i];
                }
            }
    }
    ans += (L > 0) + (R > 0);
    res = min(res, ans);
}

void Try(int i) {
    for (int j = 0; j < 2; j++) {
        x[i] = j;
        if (i == n) check();
            else Try(i + 1);
    }
}

void sub1() {
    Try(1);
    cout << res;
}

void sub2() {
    long long S = 0;
    for (int i = 1; i <= n; i++)
        S += a[i];
    cout << (S / l) + ((S % l) != 0) << endl;
}

//void sub3() {
//    long long res = 1e9;
//    for (int i = 1; i <= n; i++)
//        for (int w1 = 0; w1 <= l; w1++)
//            for (int w2 = 0; w2 <= l; w2++)
//                dp[i][w1][w2] = 1e9;
//    dp[0][0][0] = 0;
//    for (int i = 1; i <= n; i++)
//        for (int w1 = 0; w1 <= l; w1++)
//            for (int w2 = 0; w2 <= l; w2++) {
//                if (w1 + a[i] <= l) dp[i][w1 + a[i]][w2] = min(dp[i][w1 + a[i]][w2], dp[i - 1][w1][w2]);
//                    else dp[i][a[i]][w2] = min(dp[i][a[i]][w2], dp[i - 1][w1][w2] + 1);
//                if (w2 + a[i] <= l) dp[i][w1][w2 + a[i]] = min(dp[i][w1][w2 + a[i]], dp[i - 1][w1][w2]);
//                    else dp[i][w1][a[i]] = min(dp[i][w1][a[i]], dp[i - 1][w1][w2] + 1);
//            }
//    int bn = 0;
//    for (int i = 0; i <= l; i++)
//        for (int j = 0; j <= l; j++)
//            if (res > dp[n][i][j]) {
//                if (i == 0 && j == 0) bn = 0;
//                    else if (i == 0 || j == 0) bn = 1;
//                        else bn = 2;
//                if (res > bn + dp[n][i][j])
//                    res = dp[n][i][j] + bn;
//            }
//    cout << res;
//}
//
//void sub4() {
//    long long res = 1e9;
//    for (int i = 1; i <= n; i++)
//        for (int w1 = 0; w1 <= l; w1++)
//            for (int num = 0; num <= i; num++)
//                dp2[i][w1][num] = 1e9;
//    dp2[0][0][0] = 0;
//    for (int i = 1; i <= n; i++)
//        for (int w1 = 0; w1 <= l; w1++)
//            for (int num = 0; num <= i; num++)
//                if (dp2[i - 1][w1][num] < 1e9) {
//                if (dp2[i - 1][w1][num] + a[i] <= l) {
//                    dp2[i][w1][num] = min(dp2[i][w1][num], dp2[i - 1][w1][num] + a[i]);
//                }
//                    else dp2[i][w1][num + 1] = min(dp2[i][w1][num + 1], a[i]);
//                if (w1 + a[i] <= l) {
//                    dp2[i][w1 + a[i]][num] = min(dp2[i - 1][w1][num], dp2[i][w1 + a[i]][num]);
//                }
//                    else dp2[i][a[i]][num + 1] = min(dp2[i][a[i]][num + 1], dp2[i - 1][w1][num]);
//            }
//    for (int num = 0; num <= n; num++)
//        for (int w1 = 0; w1 <= l; w1++)
//        if (dp2[n][w1][num] < 1e9) {
//            cout << num + (w1 > 0) + (dp2[n][w1][num] > 0)<< endl;
//            return;
//        }
//}

ii mi(ii x, ii y) {
    if (x.first == y.first) {
        if (x.second < y.second)
            return x;
        return y;
    }
    if (x.first < y.first)
        return x;
    return y;
}

void sub5() {
    int res = 1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= l; j++)
            dp3[i][j] = {oo, oo};
    dp3[0][0] = {0, 0};
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= l; j++)
            if (dp3[i - 1][j] != make_pair(oo, oo)) {
                if (j + a[i] > l)
                    dp3[i][a[i]] = mi(dp3[i][a[i]], {dp3[i - 1][j].first + 1, dp3[i - 1][j].second});
                        else dp3[i][j + a[i]] = mi(dp3[i][j + a[i]], dp3[i - 1][j]);
                if (dp3[i - 1][j].second + a[i] > l)
                    dp3[i][j] = mi(dp3[i][j], {dp3[i - 1][j].first + 1, a[i]});
                        else dp3[i][j] = mi(dp3[i][j], {dp3[i - 1][j].first, dp3[i - 1][j].second + a[i]});
            }
    for (int j = 0; j <= l; j++)
        if (dp3[n][j] != make_pair(oo, oo)) {
            res = min(res, dp3[n][j].first + (j > 0) + (dp3[n][j].second > 0));
        }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    freopen("BINPACK.INP","r",stdin);
    freopen("BINPACK.OUT","w",stdout);
    cin >> l >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 20) sub1();
        else if (l == 100) sub2();
//            else if (n <= 10000 && l <= 30) sub3();
//                else sub4();
            else sub5();
//    sub5();
}
