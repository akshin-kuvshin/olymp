// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define pb(_elem)               push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

struct Node {
    lli cost;
    lli l_health;
    lli r_damage;

    Node(lli cost_, lli l_health_, lli r_damage_) : cost    (cost_),
                                                    l_health(l_health_),
                                                    r_damage(r_damage_) {}

    bool operator==(const Node& obj) const {
        return cost     == obj.cost
           and l_health == obj.l_health
           and r_damage == obj.r_damage;
    }
};

const Node NONE(-1LL, -1LL, -1LL);

class segtree {
private:
    vector<Node> tree;
    lli size;

    Node unite(Node a, Node b) {
        if (a == NONE)
            return b;
        if (b == NONE)
            return a;
        auto node = Node(
            a.cost + b.cost - min(a.r_damage, b.l_health),
            a.l_health,
            b.r_damage
        );
        return node;
    }

    void build(const vector<plli>& a, lli n, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < n)
                tree[x] = Node(
                    a[lx].first,
                    a[lx].first,
                    a[lx].second
                );
            return;
        }

        lli x1 = (x << 1) + 1LL,
            x2 = (x << 1) + 2LL,
            mx = (lx + rx) >> 1;
        build(a, n, x1, lx, mx);
        build(a, n, x2, mx, rx);
        tree[x] = unite(tree[x1], tree[x2]);
    }

    Node get(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return NONE;
        if (l <= lx and rx <= r)
            return tree[x];

        lli x1 = (x << 1) + 1LL,
            x2 = (x << 1) + 2LL,
            mx = (lx + rx) >> 1;
        return unite(
            get(l, r, x1, lx, mx),
            get(l, r, x2, mx, rx)
        );
    }

public:
    segtree(const vector<plli>& a, lli n) {
        size = 1LL;
        while (size < n)
            size <<= 1;
        tree.assign((size << 1) - 1LL, NONE);
        build(a, n, 0LL, 0LL, size);
    }

    Node get(lli l, lli r) {
        return get(l, r, 0LL, 0LL, size);
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
    lli n;
    cin >> n;
    vector<plli> a(n);
    for (auto& a_i : a)
        cin >> a_i.first >> a_i.second;
    for (int i = 0; i < (int)n; ++i)
        a.pb(a[i]);

    lli ans = INF;
    segtree st(a, n << 1);
    for (lli l = 0LL; l < n; ++l)
        ans = min(ans, st.get(l, l + n).cost);

    cout << ans << '\n';
}
