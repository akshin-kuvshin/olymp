// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;

    bool equal = true;
    for (auto a_i : a)
        if (a_i != a.front()) {
            equal = false;
            break;
        }
    if (equal) {
        cout << "1\n";
        while (n--)
            cout << "1 ";
        cout << '\n';
        return;
    }

    if ((n & 1LL) == 0LL) {
        cout << "2\n";
        while (n--)
            cout << 1LL + (n & 1LL) << ' ';
        cout << '\n';
        return;
    }

    vector<lli> ans(n);
    bool pair = false;
    for (int i = 0; i < (int)n; ++i) {
        int j = (i + 1) % (int)n;
        if (a[i] == a[j]) {
            ans[i] = ans[j] = 1LL;
            lli c = 2LL;
            for (j = (j + 1) % (int)n; j != i; j = (j + 1) % (int)n, c = 3LL - c)
                ans[j] = c;

            pair = true;
            break;
        }
    }
    if (not pair) {
        lli c = 1LL;
        for (int i = 0; i < (int)n; ++i, c = 3LL - c)
            ans[i] = c;
        ans.back() = 3LL;
    }

    cout << 3LL - (lli)pair << '\n';
    for (auto ans_i : ans)
        cout << ans_i << ' ';
    cout << '\n';
}
