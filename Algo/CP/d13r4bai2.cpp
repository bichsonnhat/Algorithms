#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int k, h, n;
long long a[N];
unordered_map <long long, bool> vis;
unordered_map <long long, int> l;
long long s[20], e[20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> h >> n;
    s[0] = 1;
    e[0] = 1;
    long long x = 1;
    long long pow = 1;
    for (int i = 1; i < h; i++) {
        pow *= k;
        s[i] = x + 1;
        e[i] = x + pow;
        x = x + pow;
        //cout << s[i] << " " << e[i] << endl;
    }
    long long res = 0;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (res == 0) {
            res = a[i];
            for (int j = 0; j < h; j++)
                if (res >= s[j] && res <= e[j]) {
                    l[res] = j;
                    break;
                }
            }
            else {
                for (int j = 0; j < h; j++)
                    if (a[i] >= s[j] && a[i] <= e[j]) {
                        l[a[i]] = j;
                        break;
                    }
                while (l[res] > l[a[i]]) {
                    if (!vis[res]) {
                        cnt++;
                        vis[res] = true;
                    }
                    l[(res + (k - 2)) / k] = l[res] - 1;
                    res = (res + (k - 2)) / k;
                }
                while (l[res] < l[a[i]]) {
                    if (!vis[a[i]]) {
                        cnt++;
                        vis[a[i]] = true;
                    }
                    l[(a[i] + (k - 2)) / k] = l[a[i]] - 1;
                    a[i] = (a[i] + (k - 2)) / k;
                }
                while (res != a[i]) {
                    if (!vis[a[i]]) {
                        cnt++;
                        vis[a[i]] = true;
                    }
                    if (!vis[res]) {
                        cnt++;
                        vis[res] = true;
                    }
                    l[(res + (k - 2)) / k] = l[res] - 1;
                    l[(a[i] + (k - 2)) / k] = l[a[i]] - 1;
                    res = (res + (k - 2)) / k;
                    a[i] = (a[i] + (k - 2)) / k;
                    //cout << l[res] << endl;
                }
                //cout << i << " " << res << " " << cnt << endl;
            }
    }
    cout << cnt;
}
