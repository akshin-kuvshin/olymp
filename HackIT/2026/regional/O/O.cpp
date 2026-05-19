/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const lli MOD = 1'000'000'000LL + 1'000LL - 7LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    vector<vector<lli>> dp(n, vector<lli>(m + 1LL)); // dp[i][j] - дать первым i собакам j костей в сумме
    for (int j = 1; j <= (int)m; ++j) {
        if (j == 4)
            continue;
        dp[0][j] = 1LL;
    }
    for (int i = 1; i < (int)n; ++i) {
        for (int j = i + 1; j <= (int)m; ++j) {
            for (int k = 1; k <= j - i; ++k) {
                if (k == 4)
                    continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }
    cout << dp[n - 1LL][m] << '\n';
}
