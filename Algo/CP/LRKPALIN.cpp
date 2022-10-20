#include <bits/stdc++.h>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define TASK "LRKPALIN"
#define X first
#define Y second

string s;
int k, q;
const long long MOD = 1e9 + 7;
const long long BASE = 18012003;
const int N = 1e4 + 5;
bool dp[N][N];
void Subtask_1(){
    while (q --> 0){
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        string t = s.substr(l - 1, len);
        int count = 0;
        for (int i = 0, j = len - 1; i < j; i++, j--)
            count += (t[i] != t[j]);
        cout << (count <= k) << '\n';
    }
}

long long pw(long long a, long long n) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

struct HashString {
    string str;
    vector<long long> prefixSum, inv;

    // constructor
    HashString(string str = ""): str(str) {
        int n = str.size();
        prefixSum.resize(n + 1);
        inv.resize(n + 1);

        // calc inv
        long long invBase = pw(BASE, MOD - 2) % MOD;
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            inv[i] = inv[i - 1] * invBase % MOD;
        }

        // calc prefixSum
        long long curPow = 1; // BASE ^ i
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = (prefixSum[i - 1] + curPow * str[i - 1] % MOD) % MOD;
            curPow = curPow * BASE % MOD;
        }
    }

    // return hash of str[l..r]
    long long query(int l, int r) {
        long long res = (prefixSum[r] - prefixSum[l - 1] + MOD) % MOD;
        res = res * inv[l] % MOD; // res /= pw(BASE, l)
        return res;
    }
};

void Subtask_2(){
    string a = s;
    reverse(s.begin(), s.end());
    string b = s;
    HashString hashA(a);
    HashString hashB(b);
    int n = s.size();
    while (q --> 0){
        int l, r;
        cin >> l >> r;
        long long HA = hashA.query(l, r), HB = hashB.query(n - r + 1, n - l + 1);
        cout << (HA == HB) << '\n';
    }
}

void Subtask_3(){
    string a = s, t = s;
    reverse(s.begin(), s.end());
    string b = s;
    HashString hashA(a);
    HashString hashB(b);
    int n = s.size();
    for (int i = 1; i < n; ++i){
        for (int j = i + 1; j <= n; ++j){
            long long HA = hashA.query(i, j), HB = hashB.query(n - j + 1, n - i + 1);
            if (HA == HB){
                dp[i][j] = 1;
                continue;
            } else {
                dp[i][j] = 0;
                continue;
            }
            int mid = (i + j) >> 1;
            int len = (j - i + 1);
            int l, r, count = 0;
            if (len % 2) l = mid - 1, r = mid + 1;
                else l = mid, r = mid + 1;
            while (l > i && r < j){
                count += (t[l] != t[r]);
                if (count > k) break;
                l--; r++;
            }
            dp[i][j] = (count <= k);
        }
    }
    while (q --> 0){
        int l, r;
        cin >> l >> r;
        cout << (dp[l][r]) << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    cin >> s >> k >> q;
    if (k == 0) Subtask_2();
        else Subtask_1();
    return 0;
}
