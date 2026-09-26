// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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
        d;
    cin >> n >> d;
    vector<plli> a(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i].first;
        a[i].second = (lli)i;
    }
    sort(a.begin(), a.end());

    vector<lli> ans;
    if (a[1].first - a[0].first >= d)
        ans.pb(a[0].second);
    for (int i = 1; i + 1 < (int)n; ++i)
        if (a[i].first - a[i - 1].first >= d and a[i + 1].first - a[i].first >= d)
            ans.pb(a[i].second);
    if (a[n - 1LL].first - a[n - 2LL].first >= d)
        ans.pb(a[n - 1LL].second);

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto ans_i : ans)
        cout << ++ans_i << ' ';
    cout << '\n';
}
