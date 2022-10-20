#include <bits/stdc++.h>
using namespace std;

long long n,a,b;
int square(int n) { return n * n; }

int sum(int n)
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


int oddDivSum(int a, int b)
{
    return sum(b) - sum(a - 1);
}


int main()
{
    freopen("")
    cin>>a>>b;
    cout << oddDivSum(a, b) << endl;
    return 0;
}
