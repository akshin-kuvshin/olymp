// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;

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
    lli n,
        a,
        b,
        s;
    cin >> n >> a >> b >> s;
    vector<lli> c(n);
    for (lli i = 0LL; i < n; ++i)
        c[i] = (a - i) * (b + i);
    vector<__int128_t> pref(n + 1LL);
    for (int i = 0; i < (int)n; ++i)
        pref[i + 1] = pref[i] + c[i];
    lli ans = 0LL;
    multiset<__int128_t> ms;
    for (auto p : pref) {
        ans += (lli)ms.count(p - s);
        ms.insert(p);
    }
    cout << ans << '\n';
}
