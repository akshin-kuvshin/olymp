// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N = 3LL,
          M = 6LL,
          INF = (lli)1e18 + 1LL;

void solve();
void dfs(const vector<lli>& a, const vector<lli>& b, const vector<plli>& v, vector<bool>& used, vector<plli>& p, lli& min_);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(N),
                b(N);
    for (auto& a_i : a)
        cin >> a_i;
    for (auto& b_i : b)
        cin >> b_i;

    lli max_ = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

    vector<plli> v = { {0LL, 2LL}, {0LL, 0LL}, {1LL, 0LL}, {1LL, 1LL}, {2LL, 1LL}, {2LL, 2LL} }; // (lli)v.size() == M
    vector<bool> used(M);
    vector<plli> p;
    lli min_ = INF;
    dfs(a, b, v, used, p, min_);

    cout << min_ << ' ' << max_ << '\n';
}

void dfs(const vector<lli>& a, const vector<lli>& b, const vector<plli>& v, vector<bool>& used, vector<plli>& p, lli& min_) {
    if (p.size() == v.size()) {
        vector<lli> a_ = a,
                    b_ = b;
        for (auto [i, j] : p) {
            lli x = min(a_[i], b_[j]);
            a_[i] -= x;
            b_[j] -= x;
        }
        min_ = min(min_, a_[0] + a_[1] + a_[2]);
        return;
    }

    for (int i = 0; i < (int)M; ++i) {
        if (used[i])
            continue;
        used[i] = true;
        p.push_back(v[i]);
        dfs(a, b, v, used, p, min_);
        p.pop_back();
        used[i] = false;
    }
}
