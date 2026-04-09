// author: Danila "akshin_" Axyonov & Alexander "ValeevAlex" Valeev

#include <iostream>
using namespace std;
typedef long long int lli;

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
    string s;
    cin >> s;

    lli ans = 0LL,
        cnt_i = 0LL;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (s[i] == 'i')
            ++cnt_i;
        else if (s[i] == 'a')
            ans += cnt_i;
    }
    cout << ans << '\n';
}
