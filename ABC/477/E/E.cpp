// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        q;
    cin >> n >> q;
    vector<lli> a(n),
                b(n);
    for (auto& a_i : a)
        cin >> a_i;
    for (auto& b_i : b)
        cin >> b_i;

    vector<lli> pref(n + 1LL);
    for (int i = 0; i < (int)n; ++i)
        pref[i + 1] = pref[i] + a[i];

    vector<lli> d(n);
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    for (int i = 0; i < (int)n; ++i) {
        d[i] = b[i];
        pq.push(mp(b[i], (lli)i));
    }
    while (not pq.empty()) {
        auto [dc, ic] = pq.top(); // d_current, i_current
        pq.pop();

        lli i1 = (ic + 1LL) % n,
            i2 = (ic - 1LL + n) % n;
        if (dc + a[ic] < d[i1]) {
            d[i1] = dc + a[ic];
            pq.push(mp(d[i1], i1));
        }
        if (dc + a[i2] < d[i2]) {
            d[i2] = dc + a[i2];
            pq.push(mp(d[i2], i2));
        }
    }

    while (q--) {
        lli s,
            t;
        cin >> s >> t;
        --s; --t;
        if (t == n) {
            cout << d[s] << '\n';
            continue;
        }
        vector<lli> cs; // candidates
        cs.pb(pref[t] - pref[s]);
        cs.pb(pref.back() - (pref[t] - pref[s]));
        cs.pb(d[s] + d[t]);
        sort(cs.begin(), cs.end());
        cout << cs.front() << '\n';
    }
}
