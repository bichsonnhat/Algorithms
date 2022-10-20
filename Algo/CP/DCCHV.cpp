#include <bits/stdc++.h>
using namespace std;

#define TASK "DCCHV"

const int N = 5e5 + 5;
int n, k, a[N];
vector <int> pos[N];
vector <pair <int, int> > v;
int LIS(vector <int> arr){
    int n = arr.size();
    vector<int> d(n + 1, 1000000000);
    for (int i = 0; i < n; i++) {
		*lower_bound(d.begin(), d.end(), arr[i]) = arr[i];
	}
	for (int i = 0; i <= n; i++)
		if (d[i] == 1000000000) return i;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    cin >> n >> k;
    for (int i = 1; i <= n * k; ++i) cin >> a[i];
    for (int i = 1; i <= n * k; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    for (int i = 1; i <= n * k; ++i)
        for (auto x : pos[a[i]])
            v.push_back({i, x});
    sort(v.begin(), v.end(), cmp);
    vector <int> L;
    for (auto x : v)
        L.push_back(x.second);
    cout << LIS(L);
}
