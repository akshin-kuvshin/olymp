// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

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
    lli n;
    cin >> n;
    vector<lli> a(n);
    bool all = true,
         any = false;
    for (auto& a_i : a) {
        cin >> a_i;
        if (a_i % 10LL != 0LL and a_i % 10LL != 5LL)
            all = false;
        if (a_i % 10LL == 0LL or a_i % 10LL == 5LL)
            any = true;
    }

    if (all) {
        lli min_ = *min_element(a.begin(), a.end()),
            max_ = *max_element(a.begin(), a.end());
        cout << (min_ == max_ or (min_ + 5LL == max_ and min_ % 10LL == 5LL) ? "YES" : "NO") << '\n';
        return;
    } // now all == false
    if (any) {
        cout << "NO\n";
        return;
    }

    lli max_ = *max_element(a.begin(), a.end());
    if (max_ % 10LL == 1LL or max_ % 10LL == 3LL or max_ % 10LL == 7LL or max_ % 10LL == 9LL)
        max_ += max_ % 10LL;

    const lli cycle = 2LL + 4LL + 8LL + 6LL;
    lli d[10][10]; // hell no...
    d[1][1] = 0LL; d[1][2] = 1LL; d[1][4] = 3LL; d[1][8] = 7LL; d[1][6] = 15LL;
    d[2][2] = 0LL; d[2][4] = 2LL; d[2][8] = 6LL; d[2][6] = 14LL;
    d[3][3] = 0LL; d[3][6] = 3LL; d[3][2] = 9LL; d[3][4] = 11LL; d[3][8] = 15LL;
    d[4][4] = 0LL; d[4][8] = 4LL; d[4][6] = 12LL; d[4][2] = 18LL;
    d[6][6] = 0LL; d[6][2] = 6LL; d[6][4] = 8LL; d[6][8] = 12LL;
    d[7][7] = 0LL; d[7][4] = 7LL; d[7][8] = 11LL; d[7][6] = 19LL; d[7][2] = 25LL;
    d[8][8] = 0LL; d[8][6] = 8LL; d[8][2] = 14LL; d[8][4] = 16LL;
    d[9][9] = 0LL; d[9][8] = 9LL; d[9][6] = 17LL; d[9][2] = 23LL; d[9][4] = 25LL;
    for (int i = 0; i < (int)n; ++i)
        if ((max_ - a[i] - d[a[i] % 10LL][max_ % 10LL]) % cycle != 0LL) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}
