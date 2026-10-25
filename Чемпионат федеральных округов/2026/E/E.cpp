// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const lli N = 3LL,
          MARKED = -1LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    vector<vector<lli>> b(N, vector<lli>(N));
    for (auto& b_i : b)
        for (auto& b_i_j : b_i)
            cin >> b_i_j;
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& a_i : a)
        cin >> a_i;
    vector<lli> row(N),
                col(N);
    for (int i = 0; i < (int)n; ++i) {
        for (int j = 0; j < (int)N; ++j)
            for (int k = 0; k < (int)N; ++k)
                if (b[j][k] == a[i]) {
                    b[j][k] = MARKED;
                    ++row[j];
                    ++col[k];
                }
        for (int j = 0; j < (int)N; ++j)
            if (row[j] == N or col[j] == N) {
                cout << (i + 1) << '\n';
                return;
            }
    }
    cout << "0\n";
}
