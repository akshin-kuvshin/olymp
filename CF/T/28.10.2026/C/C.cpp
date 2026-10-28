// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

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
        s;
    cin >> n >> s;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;
    vector<lli> pref(n + 1LL);
    for (int i = 0; i < (int)n; ++i)
        pref[i + 1] = pref[i] + a[i];
    lli ans = INF;
    unordered_map<lli, lli> m;
    m[pref.front()] = 0LL;
    for (int i = 1; i <= (int)n; ++i) {
        if (m.contains(pref[i] - s))
            ans = min(
                ans,
                n - ((lli)i - m[pref[i] - s])
            );
        if (not m.contains(pref[i]))
            m[pref[i]] = (lli)i;
    }
    cout << (ans == INF ? -1LL : ans) << '\n';
}
