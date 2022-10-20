#include <bits/stdc++.h>
using namespace std;

mt19937 rng(123456789);
//#define int long long

int randint(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

double uniform(double a, double b) {
	return uniform_real_distribution<double>(a, b)(rng);
}

void gen(ostream &cout, int n) {
	cout << 1 << '\n';
}

void gendb(ostream &cout, int n) {
	cout << n << '\n';
	for (int i=1; i<=n; i++) {
//        int x = rand() % n;
//        if (x <= 0 || x > n) x = 1;
        cout << 1 << ' ';
	}
	cout << endl;
}
main() {
	for (int i = 0; i < 50; i++) {
		char filename[128];
		sprintf(filename, "output.%03d", i);
		cout << filename << endl;

		std::ofstream ofs(filename);
//		int n = 200000, m = 1;
        int n = 1000000000000;
//		double threshold = uniform(0.0, 1.0);
		gen(ofs, n);
	}
}
