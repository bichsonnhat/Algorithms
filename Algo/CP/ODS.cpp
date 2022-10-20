#include <bits/stdc++.h>
using namespace std;

long long n,a,b;
long long square(long long n) { return n * n; }

long long sum(long long n)
{
    if (n == 0)
        return 0;
    if (n % 2 == 1) {  // Odd n
        return square((n + 1) / 2) + sum(n / 2);
    }
    else { // Even n
        return square(n / 2) + sum(n / 2);
    }
}


long long oddDivSum(long long a, long long b)
{
    return sum(b) - sum(a - 1);
}


int main()
{
    freopen("ODS.INP", "r", stdin);
    freopen("ODS.OUT", "w", stdout);
    int t;
    cin >> t;
    while (t--){
    cin>>a>>b;
    cout << oddDivSum(a, b) << endl;
    }
    return 0;
}
