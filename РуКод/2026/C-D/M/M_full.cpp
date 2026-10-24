// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MOD = 998'244'353LL;

void solve();
lli bin_pow(lli base, lli ptr);
lli inv(lli a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        b;
    cin >> b >> n;

    if (n & 1LL) {
        cout << "0\n";
        return;
    }

    lli m = n >> 1;
    lli numerator = 1LL;
    for (lli i = b - 1LL; i <= b + m - 2LL; ++i)
        numerator = (numerator * (i % MOD)) % MOD;
    lli denominator = 1LL;
    for (lli i = 1LL; i <= m; ++i)
        denominator = (denominator * i) % MOD;
    denominator = inv(denominator);
    lli ans = (numerator * denominator) % MOD;
    cout << ans << '\n';
}

lli bin_pow(lli base, lli ptr) {
    if (not ptr)
        return 1LL;
    if (ptr & 1LL)
        return (bin_pow(base, ptr - 1LL) * base) % MOD;
    lli half = bin_pow(base, ptr >> 1);
    return (half * half) % MOD;
}

lli inv(lli a) {
    return bin_pow(a, MOD - 2LL);
}
