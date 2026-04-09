// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

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
        k;
    cin >> n >> k;
    vector<lli> a(n),
                p(k);
    for (lli& ai : a)
        cin >> ai;
    for (lli& pi : p) {
        cin >> pi;
        --pi;
    }

    lli cnt_l = 0LL,
        cnt_r = 0LL;
    for (int i = (int)p.front() - 1; i >= 0; --i)
        if (a[i] != a[i + 1])
            ++cnt_l;
    for (int i = (int)p.front() + 1; i < (int)n; ++i)
        if (a[i - 1] != a[i])
            ++cnt_r;

    lli ans = max(cnt_l, cnt_r);
    ans += ans % 2LL;
    cout << ans << '\n';
}
