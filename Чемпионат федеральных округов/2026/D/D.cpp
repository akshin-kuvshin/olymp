// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const vector<lli> c = {2LL, 4LL, 7LL, 9LL, 12LL, 14LL, 18LL, 21LL, 24LL, 26LL, 29LL, 30LL};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli l,
        r;
    cin >> l >> r;
    lli ans = 0LL;
    for (auto c_i : c)
        if (l <= c_i and c_i <= r)
            ++ans;
    cout << ans << '\n';
}
