// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli INF = (lli)1e18 + 1LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;
    vector<lli> pref(n);
    pref.front() = a.front();
    for (int i = 1; i < (int)n; ++i)
        pref[i] = pref[i - 1] + a[i];
    lli min_ = *min_element(pref.begin(), pref.end()),
        max_ = *max_element(pref.begin(), pref.end());
    lli d = INF;
    for (int i = 0; i < (int)n; ++i)
        d = min(d, max(max_ - pref[i], pref[i] - min_));
    lli ans = 0LL;
    for (int i = 0; i < (int)n; ++i)
        if (max(max_ - pref[i], pref[i] - min_) == d)
            ++ans;
    cout << ans << '\n';
}
