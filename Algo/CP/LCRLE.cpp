#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

const int N = 3003;
int m, n;
string a, b;
char ca[N], cb[N];
llint numa[N], numb[N], G[N][N], F[N][N];
bool FF[N][N];

int analyze(string a, char b[], llint c[], int& len)
{
    len = 0;
	for (int i = 0; i < a.length(); i++) {
        char cc = a[i];
		if (cc >= 'a') b[++len]=cc;
		else c[len] = c[len] * 10 + (cc - '0');
	}
	return len;
}

llint f(int m, int n) {

	if (m == 0 || n == 0) return 0;
	if (F[m][n] > -1) return F[m][n];
	F[m][n] = 0;
	llint Max = max(f(m-1, n), f(m, n-1));
	if (ca[m]!=cb[n]) return F[m][n] = Max;

	char c = ca[m];
	int i = m - 1, j = n - 1;
	llint A = numa[m], B = numb[n];
	Max = max(Max, f(i, j) + min(A, B));

	while (i || j) {
		if (i == 0 && A <= B || j == 0 && B <= A) break;
		while (i && A <= B) if (ca[i--]==c)
		{ A += numa[i+1]; Max = max(Max, f(i, j) + min(A, B)); }
		while (j && B <= A) if (cb[j--]==c)
		{ B+=numb[j+1]; Max = max(Max, f(i, j) + min(A, B)); }
	}

	return F[m][n] = Max;

}

int main() {
	freopen("lcrle.inp", "r", stdin);
	freopen("lcrle.out", "w", stdout);
	cin>> a >> b;
	analyze(a, ca, numa, m);
	analyze(b, cb, numb, n);

	memset(F, -1, sizeof F);

	cout << f(m, n) << endl;

    memset(F, 0, sizeof F);

	llint Max = 0;
	for (int i = m; i >= 1; i--)
        for (int j = n; j >= 1; j--)
            if (ca[i]==cb[j]) {
                if (numa[i] == numb[j]) {
                F[i][j] = F[i+1][j+1] + numa[i];
                Max = max(Max, F[i][j]);
            } else {
                F[i][j] = min(numa[i], numb[j]);
                Max = max(Max, min(numa[i], numb[j]) + F[i+1][j+1]);
            }
	}
	cout << Max << endl;
}
