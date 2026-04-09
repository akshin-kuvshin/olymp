// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli gcd_R(lli a, lli b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}

void solve() {
    lli n,
        m,
        a,
        b;
    cin >> n >> m >> a >> b;

    lli gcd_na = gcd_R(n, a),
        gcd_mb = gcd_R(m, b),
        gcd_nm = gcd_R(n, m);
    lli lcm_nm = n / gcd_nm * m;

    cout << (gcd_na == 1LL and gcd_mb == 1LL and 2LL * lcm_nm >= n * m ? "YES" : "NO") << '\n';
}

lli gcd_R(lli a, lli b) {
    return ((a && b) ? gcd_R(b, a % b) : (a | b));
}
