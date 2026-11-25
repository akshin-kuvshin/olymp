// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli H_MAX = (lli)1e9;

void solve();
lli ts(const vector<lli>& h, lli a, lli r, lli m);
lli f(const vector<lli>& h, lli a, lli r, lli m, lli x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        a,
        r,
        m;
    cin >> n >> a >> r >> m;
    vector<lli> h(n);
    for (auto& h_i : h)
        cin >> h_i;

    lli ans = ts(h, a, r, m);

    cout << ans << '\n';
}

lli ts(const vector<lli>& h, lli a, lli r, lli m) {
    lli l = 0LL,
        r_ = H_MAX + 1LL;

    while (l + 2LL < r_) {
        lli x1 = ((l << 1) + r_) / 3LL,
            x2 = (l + (r_ << 1)) / 3LL;
        if (f(h, a, r, m, x1) > f(h, a, r, m, x2))
            l = x1;
        else // f(h, a, r, m, x1) <= f(h, a, r, m, x2)
            r_ = x2;
    }

    vector<lli> candidates = {
        f(h, a, r, m, l),
        f(h, a, r, m, l + 1LL),
        f(h, a, r, m, l + 2LL)
    };
    return *min_element(candidates.begin(), candidates.end());
}

lli f(const vector<lli>& h, lli a, lli r, lli m, lli x) {
    lli res = 0LL;

    if (a + r <= m) {
        for (auto h_i : h)
            if (h_i < x)
                res += (x - h_i) * a;
            else if (h_i > x)
                res += (h_i - x) * r;
    } else { // m < a + r
        lli to_remove = 0LL;
        for (auto h_i : h)
            if (h_i > x)
                to_remove += h_i - x;

        lli balance = to_remove;
        for (auto h_i : h)
            if (h_i < x)
            balance -= x - h_i;

        if (balance < 0LL)
            res = to_remove * m + (-balance) * a;
        else if (balance == 0LL)
            res = to_remove * m;
        else // balance > 0LL
            res = (to_remove - balance) * m + balance * r;
    }

    return res;
}
