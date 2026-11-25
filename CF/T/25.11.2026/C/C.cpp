// author: Danila "akshin_" Axyonov
// stupid...

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const lli INF = (lli)1e18 + 1LL,
          X_MAX = (lli)1e4;

class segtree {
private:
    vector<lli> tree;
    lli size;

    void set_min(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = min(tree[x], val);
            return;
        }

        lli x1 = (x << 1) + 1LL,
            x2 = (x << 1) + 2LL,
            mx = (lx + rx) >> 1;
        if (i < mx)
            set_min(i, val, x1, lx, mx);
        else // mx <= i
            set_min(i, val, x2, mx, rx);
        tree[x] = min(tree[x1], tree[x2]);
    }

    lli get_min(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return INF;
        if (l <= lx and rx <= r)
            return tree[x];

        lli x1 = (x << 1) + 1LL,
            x2 = (x << 1) + 2LL,
            mx = (lx + rx) >> 1;
        return min(
            get_min(l, r, x1, lx, mx),
            get_min(l, r, x2, mx, rx)
        );
    }

public:
    segtree(lli n) {
        size = 1LL;
        while (size < n)
            size <<= 1;
        tree.assign((size << 1) - 1LL, INF);
    }

    void set_min(lli i, lli val) {
        set_min(i, val, 0LL, 0LL, size);
    }

    lli get_min_ex(lli i) {
        return min(
            get_min(0LL, i, 0LL, 0LL, size),
            get_min(i + 1LL, size, 0LL, 0LL, size)
        );
    }
};

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
        x;
    cin >> n >> x;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;

    vector<lli> prefix(n + 1LL);
    for (int i = 0; i < (int)n; ++i)
        prefix[i + 1] = prefix[i] + a[i];

    lli ans = -1LL;
    segtree st(X_MAX);
    for (lli r = 0LL; r <= n; ++r) {
        lli l = st.get_min_ex(prefix[r] % x);
        if (l != INF)
            ans = max(ans, r - l);
        st.set_min(prefix[r] % x, r);
    }

    cout << ans << '\n';
}
