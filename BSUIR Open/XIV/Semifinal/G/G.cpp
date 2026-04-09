// author: Danila "akshin_" Axyonov & Alexander "ValeevAlex" Valeev

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define x first
#define y second

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<plli> a(n);
    for (auto& ai : a) {
        cin >> ai.x >> ai.y;
        --ai.x;
        --ai.y;
    }

    lli ans = 0LL;
    for (auto ai : a)
        ans += ai.x * n + (ai.y + 1);

    vector<lli> drows(n),
                dcols(n);
    lli row_shift = 0LL,
        col_shift = 0LL;

    lli q;
    cin >> q;
    while (q--) {
        lli cmd;
        cin >> cmd;

        if (cmd == 1LL) {
            char d;
            lli k;
            cin >> d >> k;
            if (d == 'U')
                row_shift = (row_shift + k) % n;
            else if (d == 'D')
                row_shift = (row_shift - k + n) % n;
            else if (d == 'L')
                col_shift = (col_shift + k) % n;
            else // d == 'R'
                col_shift = (col_shift - k + n) % n;
        } else if (cmd == 2LL) {
            char l;
            lli r,
                dx;
            cin >> l >> r >> dx;
            --r;
            if (l == 'R')
                drows[(r + row_shift) % n] += dx;
            else // l == 'C'
                dcols[(r + col_shift) % n] += dx;
            ans += dx;
        } else if (cmd == 3LL) {
            lli tmp;
            cin >> tmp >> tmp;
        } else // cmd == 4LL
            cout << ans << '\n';
    }
}
