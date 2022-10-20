#include <bits/stdc++.h>
using namespace std;

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
//typedef tree< double, int, less<double>, rb_tree_tag, tree_order_statistics_node_update> map_t;


#define TASK "DAYSO"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORTYPE(type, i, l, r) for (type i = l; i <= r; i++)
#define FODTYPE(type, i, l, r) for (type i = l; i >= r; i--)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define prec(n) fixed<<setprecision(n)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define upper upper_bound
#define lower lower_bound
#define itr iterator
#define rtr reverse_iterator
#define memset(a,x) memset(a, x, sizeof(a))
#define memsetf(a) memset(a, 0x3f, sizeof(a))
#define um unordered_map
#define us unordered_set
#define pq priority_queue
#define GetMask ((x >> i) & 1)
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
const ll N = 65;
const ll MOD = 1e9 + 7;
//const ll BASE = 1000;
const ll DIGIT = 4;
const ll LIM = (1 << 24);
const ll INF = (1 << 30);
const ll LIMIT = 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
const int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int oo = 1e9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll binPow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return binPow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
//mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
//inline int mrand() {return abs((int) mt());}
//inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

/// ================================ - MAIN - ================================

// ====================================================================
const int BASE_DIGITS = 9;
const int BASE = 1e9;
struct BigInt {
    int sign;
    std::vector<int> a;
    // -------------------- Constructors --------------------
    // Default constructor.
    BigInt() : sign(1) {}
    // Constructor from long long.
    BigInt(long long v) {
        *this = v;
    }
    BigInt& operator = (long long v) {
        sign = 1;
        if (v < 0) {
            sign = -1;
            v = -v;
        }
        a.clear();
        for (; v > 0; v = v / BASE)
            a.push_back(v % BASE);
        return *this;
    }
    // Initialize from string.
    BigInt(const std::string& s) {
        read(s);
    }
    // -------------------- Input / Output --------------------
    void read(const std::string& s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= BASE_DIGITS) {
            int x = 0;
            for (int j = std::max(pos, i - BASE_DIGITS + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend std::istream& operator>>(std::istream &stream, BigInt &v) {
        std::string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    friend std::ostream& operator<<(std::ostream &stream, const BigInt &v) {
        if (v.sign == -1 && !v.isZero())
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << std::setw(BASE_DIGITS) << std::setfill('0') << v.a[i];
        return stream;
    }
    // -------------------- Comparison --------------------
    bool operator<(const BigInt &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = ((int) a.size()) - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }
    bool operator>(const BigInt &v) const {
        return v < *this;
    }
    bool operator<=(const BigInt &v) const {
        return !(v < *this);
    }
    bool operator>=(const BigInt &v) const {
        return !(*this < v);
    }
    bool operator==(const BigInt &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const BigInt &v) const {
        return *this < v || v < *this;
    }
    // Returns:
    // 0 if |x| == |y|
    // -1 if |x| < |y|
    // 1 if |x| > |y|
    friend int __compare_abs(const BigInt& x, const BigInt& y) {
        if (x.a.size() != y.a.size()) {
            return x.a.size() < y.a.size() ? -1 : 1;
        }
        for (int i = ((int) x.a.size()) - 1; i >= 0; --i) {
            if (x.a[i] != y.a[i]) {
                return x.a[i] < y.a[i] ? -1 : 1;
            }
        }
        return 0;
    }
    // -------------------- Unary operator - and operators +- --------------------
    BigInt operator-() const {
        BigInt res = *this;
        if (isZero()) return res;
        res.sign = -sign;
        return res;
    }
    // Note: sign ignored.
    void __internal_add(const BigInt& v) {
        if (a.size() < v.a.size()) {
            a.resize(v.a.size(), 0);
        }
        for (int i = 0, carry = 0; i < (int) std::max(a.size(), v.a.size()) || carry; ++i) {
            if (i == (int) a.size()) a.push_back(0);
            a[i] += carry + (i < (int) v.a.size() ? v.a[i] : 0);
            carry = a[i] >= BASE;
            if (carry) a[i] -= BASE;
        }
    }
    // Note: sign ignored.
    void __internal_sub(const BigInt& v) {
        for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
            a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
            carry = a[i] < 0;
            if (carry) a[i] += BASE;
        }
        this->trim();
    }
    BigInt operator += (const BigInt& v) {
        if (sign == v.sign) {
            __internal_add(v);
        } else {
            if (__compare_abs(*this, v) >= 0) {
                __internal_sub(v);
            } else {
                BigInt vv = v;
                std::swap(*this, vv);
                __internal_sub(vv);
            }
        }
        return *this;
    }
    BigInt operator -= (const BigInt& v) {
        if (sign == v.sign) {
            if (__compare_abs(*this, v) >= 0) {
                __internal_sub(v);
            } else {
                BigInt vv = v;
                std::swap(*this, vv);
                __internal_sub(vv);
                this->sign = -this->sign;
            }
        } else {
            __internal_add(v);
        }
        return *this;
    }
    // Optimize operators + and - according to
    // https://stackoverflow.com/questions/13166079/move-semantics-and-pass-by-rvalue-reference-in-overloaded-arithmetic
    template< typename L, typename R >
    typename std::enable_if <
    std::is_convertible<L, BigInt>::value &&
    std::is_convertible<R, BigInt>::value &&
    std::is_lvalue_reference < R&& >::value,
    BigInt >::type friend operator + (L&& l, R&& r) {
        BigInt result(std::forward<L>(l));
        result += r;
        return result;
    }
    template< typename L, typename R >
    typename std::enable_if <
    std::is_convertible<L, BigInt>::value &&
    std::is_convertible<R, BigInt>::value &&
    std::is_rvalue_reference < R&& >::value,
    BigInt >::type friend operator + (L&& l, R&& r) {
        BigInt result(std::move(r));
        result += l;
        return result;
    }
    template< typename L, typename R >
    typename std::enable_if <
    std::is_convertible<L, BigInt>::value &&
    std::is_convertible<R, BigInt>::value,
    BigInt >::type friend operator - (L&& l, R&& r) {
        BigInt result(std::forward<L>(l));
        result -= r;
        return result;
    }
    // -------------------- Operators * / % --------------------
    friend std::pair<BigInt, BigInt> divmod(const BigInt& a1, const BigInt& b1) {
        assert(b1 > 0);  // divmod not well-defined for b < 0.
        long long norm = BASE / (b1.a.back() + 1);
        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;
        BigInt q = 0, r = 0;
        q.a.resize(a.a.size());
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= BASE;
            r += a.a[i];
            long long s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            long long s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            long long d = ((long long) BASE * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0) {
                r += b, --d;
            }
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        auto res = std::make_pair(q, r / norm);
        if (res.second < 0) res.second += b1;
        return res;
    }
    BigInt operator/(const BigInt &v) const {
        return divmod(*this, v).first;
    }
    BigInt operator%(const BigInt &v) const {
        return divmod(*this, v).second;
    }
    void operator/=(int v) {
        assert(v > 0);  // operator / not well-defined for v <= 0.
        if (llabs(v) >= BASE) {
            *this /= BigInt(v);
            return ;
        }
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) BASE;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }
    BigInt operator/(int v) const {
        assert(v > 0);  // operator / not well-defined for v <= 0.
        if (llabs(v) >= BASE) {
            return *this / BigInt(v);
        }
        BigInt res = *this;
        res /= v;
        return res;
    }
    void operator/=(const BigInt &v) {
        *this = *this / v;
    }
    long long operator%(long long v) const {
        assert(v > 0);  // operator / not well-defined for v <= 0.
        assert(v < BASE);
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) BASE) % v;
        return m * sign;
    }
    void operator*=(int v) {
        if (llabs(v) >= BASE) {
            *this *= BigInt(v);
            return ;
        }
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / BASE);
            a[i] = (int) (cur % BASE);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
            /*
             int val;
             __asm {
             lea esi, cur
             mov eax, [esi]
             mov edx, [esi+4]
             mov ecx, base
             div ecx
             mov carry, eax
             mov val, edx;
             }
             a[i] = val;
             */
        }
        trim();
    }
    BigInt operator*(int v) const {
        if (llabs(v) >= BASE) {
            return *this * BigInt(v);
        }
        BigInt res = *this;
        res *= v;
        return res;
    }
    // Convert BASE 10^old --> 10^new.
    static std::vector<int> convert_base(const std::vector<int> &a, int old_digits, int new_digits) {
        std::vector<long long> p(std::max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        std::vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back((long long)(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
    void fft(std::vector<std::complex<double> > & a, bool invert) const {
        int n = (int) a.size();
        for (int i = 1, j = 0; i < n; ++i) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
                swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * 3.14159265358979323846 / len * (invert ? -1 : 1);
            std::complex<double> wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                std::complex<double> w(1);
                for (int j = 0; j < len / 2; ++j) {
                    std::complex<double> u = a[i + j];
                    std::complex<double> v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert)
            for (int i = 0; i < n; ++i)
                a[i] /= n;
    }
    void multiply_fft(const std::vector<int> &a, const std::vector<int> &b, std::vector<int> &res) const {
        std::vector<std::complex<double> > fa(a.begin(), a.end());
        std::vector<std::complex<double> > fb(b.begin(), b.end());
        int n = 1;
        while (n < (int) std::max(a.size(), b.size()))
            n <<= 1;
        n <<= 1;
        fa.resize(n);
        fb.resize(n);
        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; ++i)
            fa[i] *= fb[i];
        fft(fa, true);
        res.resize(n);
        long long carry = 0;
        for (int i = 0; i < n; ++i) {
            long long t = (long long) (fa[i].real() + 0.5) + carry;
            carry = t / 1000;
            res[i] = t % 1000;
        }
    }
    BigInt mul_simple(const BigInt &v) const {
        BigInt res;
        res.sign = sign * v.sign;
        res.a.resize(a.size() + v.a.size());
        for (int i = 0; i < (int) a.size(); ++i)
            if (a[i])
                for (int j = 0, carry = 0; j < (int) v.a.size() || carry; ++j) {
                    long long cur = res.a[i + j] + (long long) a[i] * (j < (int) v.a.size() ? v.a[j] : 0) + carry;
                    carry = (int) (cur / BASE);
                    res.a[i + j] = (int) (cur % BASE);
                }
        res.trim();
        return res;
    }
    typedef std::vector<long long> vll;
    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];
        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];
        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }
    BigInt mul_karatsuba(const BigInt &v) const {
        std::vector<int> a6 = convert_base(this->a, BASE_DIGITS, 6);
        std::vector<int> b6 = convert_base(v.a, BASE_DIGITS, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        BigInt res;
        res.sign = sign * v.sign;
        long long carry = 0;
        for (int i = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = cur / 1000000;
        }
        res.a = convert_base(res.a, 6, BASE_DIGITS);
        res.trim();
        return res;
    }
    void operator*=(const BigInt &v) {
        *this = *this * v;
    }
    BigInt operator*(const BigInt &v) const {
        if (a.size() * v.a.size() <= 1000111) return mul_simple(v);
        if (a.size() > 500111 || v.a.size() > 500111) return mul_fft(v);
        return mul_karatsuba(v);
    }
    BigInt mul_fft(const BigInt& v) const {
        BigInt res;
        res.sign = sign * v.sign;
        multiply_fft(convert_base(a, BASE_DIGITS, 3), convert_base(v.a, BASE_DIGITS, 3), res.a);
        res.a = convert_base(res.a, 3, BASE_DIGITS);
        res.trim();
        return res;
    }
    // -------------------- Misc --------------------
    BigInt abs() const {
        BigInt res = *this;
        res.sign *= res.sign;
        return res;
    }
    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
    friend BigInt gcd(const BigInt &a, const BigInt &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend BigInt lcm(const BigInt &a, const BigInt &b) {
        return a / gcd(a, b) * b;
    }
    friend BigInt sqrt(const BigInt &a1) {
        BigInt a = a1;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);
        int n = a.a.size();
        int firstDigit = (int) sqrt((double) a.a[n - 1] * BASE + a.a[n - 2]);
        int norm = BASE / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);
        BigInt r = (long long) a.a[n - 1] * BASE + a.a[n - 2];
        firstDigit = (int) sqrt((double) a.a[n - 1] * BASE + a.a[n - 2]);
        int q = firstDigit;
        BigInt res;
        for (int j = n / 2 - 1; j >= 0; j--) {
            for (; ; --q) {
                BigInt r1 = (r - (res * 2 * BigInt(BASE) + q) * q) * BigInt(BASE) * BigInt(BASE) + (j > 0 ? (long long) a.a[2 * j - 1] * BASE + a.a[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= BASE;
            res += q;
            if (j > 0) {
                int d1 = res.a.size() + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;
                int d2 = res.a.size() + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;
                int d3 = res.a.size() < r.a.size() ? r.a[res.a.size()] : 0;
                q = ((long long) d1 * BASE * BASE + (long long) d2 * BASE + d3) / (firstDigit * 2);
            }
        }
        res.trim();
        return res / norm;
    }
};
// ====================================================================

BigInt f[N];

void Pre_Compute(){
    f[0] = 1;
    for (int i = 1; i < N; ++i){
        f[i] = f[i - 1] * 3;
    }
}

void Solve(){
    long long n;
    Pre_Compute();
    while (cin >> n){
        vector <int> p;
        while (n > 0){
            p.push_back(n % 2);
            n >>= 1;
        }
        BigInt ans = 0;
        for (int i = 0; i < (int) p.size(); ++i){
            if (p[i]) {
                ans += f[i];
            }
        }
        cout << ans << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int ntest = 1;
//    cin >> ntest;
    while (ntest--){
        Solve();
    }
}
