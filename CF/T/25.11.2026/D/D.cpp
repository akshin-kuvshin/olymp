// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const int LOG = 60;

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
    lli n;
    cin >> n;

    vector<lli> cnt(LOG + 1);
    cnt[1] = n;
    for (int i = 2; i <= LOG; ++i) {
        cnt[i] = cnt[i - 1] >> 1;
        cnt[i - 1] -= cnt[i];
    }

    lli ans = 0LL;
    for (int i = 1; i <= LOG; ++i)
        ans += cnt[i] * (lli)i;

    cout << ans << '\n';
}
