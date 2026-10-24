/* authors:
1) Danila "akshin_" Axyonov;
2) Alexander "Valeev_Alex" Valeev;
3) Nikita "benchik_228" Terebinov.
*/

#include <iostream>
#include <vector>
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
    lli n,
        k;
    cin >> n >> k;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;

    for (lli i = 1LL; i <= k; ++i) {
        vector<lli> v(n);
        v.back() = 1LL;
        lli ost = i - 1LL;
        v.front() += ost;

        for (int j = 1; j < (int)n; ++j) {
            if (v.front() < 2LL)
                break;
            if (a[j] - a.front() >= 20LL)
                break;
            ++v[j];
            --v.front();
        }

        lli ans = 0LL,
            l = 0LL;
        for (int j = 0; j < (int)n; ++j)
            if (v[j]) {
                ans += v[j] * (a[j] * 60LL + 1200LL * l) / i;
                l = 0LL;
            } else
                ++l;
        cout << ans << '\n';
    }
}
