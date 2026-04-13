// author: Danila "akshin_" Axyonov
// idea: Nikita "KuzlyaevNikita" Kuzlyaev
// [UNTESTED]

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using lli = long long int;

const lli N = 2'000LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<lli>> f(N + 1LL, vector<lli>(N + 1LL, -1LL));
    for (lli a = 0LL; a <= N; ++a)
        for (lli b = 0LL; b <= N; ++b) {
            if (f[a][b] >= 0LL)
                continue;

            f[a][b] = 1LL;
            for (lli aa = a + 1LL; aa <= N; ++aa)
                f[aa][b] = 0LL;
            for (lli bb = b + 1LL; bb <= N; ++bb)
                f[a][bb] = 0LL;
            for (lli aa = a + 1LL, bb = b + 1LL; aa <= N and bb <= N; ++aa, ++bb)
                f[aa][bb] = 0LL;
        }

    vector<string> ans = {"first\n", "second\n"};

    lli q;
    cin >> q;
    while (q--) {
        lli a,
            b;
        cin >> a >> b;
        cout << ans[f[a][b]];
    }

    return 0;
}
