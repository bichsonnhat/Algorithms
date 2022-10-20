#include <bits/stdc++.h>
using namespace std;

long long res(long long arr[], long long n)
{
    sort(arr,arr + n);
    long long count = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        int k = i + 2;
        for (int j = i + 1; j < n; ++j)
        {
            while (k < n && arr[i] + arr[j] > arr[k])
            ++k;
            if(k > j)
            count += k - j - 1;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    long long n;
    cin>>n;
    long long arr[n];
    for (int i=0; i<n; i++)
        cin>>arr[i];
    cout<<res( arr, n );
    return 0;
}
