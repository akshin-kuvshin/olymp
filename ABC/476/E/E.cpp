// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 67LL;



class segtree {
private:
    lli size;
    vector<plli> min_;
    vector<plli> max_;

    void build(const vector<lli>& a, lli n, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < n)
                min_[x] = max_[x] = mp(a[lx], lx);
            return;
        }
        lli x1 = 2LL * x + 1LL,
            x2 = 2LL * x + 2LL,
            m = (lx + rx) / 2LL;
        build(a, n, x1, lx, m);
        build(a, n, x2, m, rx);
        min_[x] = min(min_[x1], min_[x2]);
        max_[x] = max(max_[x1], max_[x2]);
    }

    void set(lli val, lli i, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            min_[x].first = max_[x].first = val;
            return;
        }
        lli x1 = 2LL * x + 1LL,
            x2 = 2LL * x + 2LL,
            m = (lx + rx) / 2LL;
        if (i < m)
            set(val, i, x1, lx, m);
        else // m <= i
            set(val, i, x2, m, rx);
        min_[x] = min(min_[x1], min_[x2]);
        max_[x] = max(max_[x1], max_[x2]);
    }

    pair<plli, plli> get(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return mp(
                mp(INF, -1LL),
                mp(-INF, -1LL)
            );
        if (l <= lx and rx <= r)
            return mp(min_[x], max_[x]);
        lli x1 = 2LL * x + 1LL,
            x2 = 2LL * x + 2LL,
            m = (lx + rx) / 2LL;
        auto res1 = get(l, r, x1, lx, m);
        auto res2 = get(l, r, x2, m, rx);
        return mp(
            min(res1.first, res2.first),
            max(res1.second, res2.second)
        );
    }

public:
    segtree(const vector<lli>& a, lli n) {
        size = 1LL;
        while (size < n)
            size *= 2LL;
        min_.assign(2LL * size - 1LL, mp(INF, -1LL));
        max_.assign(2LL * size - 1LL, mp(-INF, -1LL));
        build(a, n, 0LL, 0LL, size);
    }

    void set(lli val, lli i) {
        set(val, i, 0LL, 0LL, size);
    }

    void min_max_swap(lli l, lli r) {
        auto [min_p, max_p] = get(l, r, 0LL, 0LL, size);
        set(min_p.first, max_p.second);
        set(max_p.first, min_p.second);
    }

    vector<lli> to_vector() {
        vector<lli> v(size);
        for (int i = 0; i < (int)size; ++i)
            v[i] = min_[(int)size - 1 + i].first;
        return v;
    }
};



void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    vector<lli> p(n);
    for (auto& pi : p)
        cin >> pi;
    segtree st(p, n);

    while (m--) {
        lli l,
            r;
        cin >> l >> r;
        --l;
        st.min_max_swap(l, r);
    }

    p = st.to_vector();
    for (int i = 0; i < (int)n; ++i)
        cout << p[i] << ' ';
    cout << '\n';
}
