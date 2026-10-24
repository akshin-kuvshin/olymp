/* authors:
1) Danila "akshin_" Axyonov;
2) Alexander "Valeev_Alex" Valeev;
3) Nikita "benchik_228" Terebinov.
*/

// solution for 40 points out of 60

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const lli MOD = 998'244'353LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        b;
    cin >> b >> n;

    if (n & 1LL) {
        cout << "0\n";
        return;
    }

    lli m = (n >> 1);
    vector<vector<lli>> dp(m, vector<lli>(b - 1LL));
    for (int j = 0; j < (int)b - 1; ++j)
        dp[0][j] = 1LL;
    for (int i = 1; i < (int)m; ++i)
        for (int j = 0; j < (int)b - 1; ++j)
            for (int k = 0; k <= j; ++k)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;

    lli ans = 0LL;
    for (int j = 0; j < (int)b - 1; ++j)
        ans = (ans + dp[m - 1LL][j]) % MOD;
    cout << ans << '\n';
}
