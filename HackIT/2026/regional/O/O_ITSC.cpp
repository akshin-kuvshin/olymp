// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

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
    m -= n;

    vector<vector<lli>> dp(n, vector<lli>(m + 1LL));
    // dp[i][j] - кол-во способов раздать (j) костей в сумме
    // первым (i) собакам.

    for (int j = 0; j <= (int)m; ++j) {
        if (j == 3)
            continue;
        dp[0][j] = 1LL;
    }
    for (int i = 1; i < (int)n; ++i)
        for (int j = 0; j <= (int)m; ++j)
            // как пересчитать dp[i][j]?
            // 1) текущей собаке даём 0 костей => dp[i - 1][j]
            // 2) текущей собаке даём 1 кость => dp[i - 1][j - 1]
            // 3) текущей собаке даём 2 кости => dp[i - 1][j - 2]
            // ...
            // j + 1) текущей собаке даём j костей => dp[i - 1][0]

            for (int k = 0; k <= j; ++k) {
                if (j - k == 3)
                    continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }

    cout << dp.back().back() << '\n';
}

/*
n = 3
m = 10
m -= n => m = 7

  0  1  2  3  4  5  6  7
 ------------------------
0|1  1  1  0  1  1  1  1
1|1  2  3  2  3  4  6  6
2|1  3  6  7  9  12 19 24
*/
