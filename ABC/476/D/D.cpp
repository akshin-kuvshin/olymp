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
        m,
        k,
        x,
        y;
    cin >> n >> m >> k >> x >> y;
    vector<lli> a(n),
                b(m);
    for (auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    lli b_sum = 0LL,
        dy_total = 0LL;
    int j = 0;
    while (j < (int)m and dy_total < y) {
        b_sum += b[j];
        dy_total += (b[j++] + k - 1LL) / k;
    }
    if (dy_total > y) {
        b_sum -= b[--j];
        dy_total -= (b[j] + k - 1LL) / k;
    }

    lli a_sum = 0LL;
    int i = 0;
    while (i < (int)n and a_sum < x + (k * dy_total - b_sum) + k * (y - dy_total))
        a_sum += a[i++];
    if (a_sum > x + (k * dy_total - b_sum) + k * (y - dy_total))
        a_sum -= a[--i];

    lli ans = (lli)(i + j);
    while (j > 0) {
        b_sum -= b[--j];
        dy_total -= (b[j] + k - 1LL) / k;
        while (i < (int)n and a_sum < x + (k * dy_total - b_sum) + k * (y - dy_total))
            a_sum += a[i++];
        if (a_sum > x + (k * dy_total - b_sum) + k * (y - dy_total))
            a_sum -= a[--i];
        ans = max(ans, (lli)(i + j));
    }

    cout << ans << '\n';
}
