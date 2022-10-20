#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int m = 1;
    for (int i = 1; i <= n; ++i){
        if (m == a[i]) m++;
            else {
                cout << m << '\n';
                return 0;
            }
    }
    cout << a[1] - 1 << '\n';
    return 0;
}
