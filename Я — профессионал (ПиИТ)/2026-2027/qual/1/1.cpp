// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli b,
        n;
    cin >> b >> n;

    lli ans = 0LL,
        pow_b = 1LL;
    while (pow_b <= n) {
        ans += n / pow_b;
        pow_b *= b; // overflow?
    }

    cout << ans << '\n';
}
