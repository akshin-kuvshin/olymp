// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N_MAX = 20'000LL;

void solve();

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
    lli p,
        q;
    cin >> p >> q;

    for (lli n = 1LL; n <= N_MAX; ++n) {
        lli a = p + 2LL * q - n;
        if (a <= 0LL)
            break;
        if (a % (2LL * n + 1LL) != 0LL)
            continue;
        lli m = a / (2LL * n + 1LL);
        if (p < abs(n - m))
            continue;
        cout << n << ' ' << m << '\n';
        return;
    }
    cout << "-1\n";
}
