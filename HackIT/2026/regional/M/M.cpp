/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;
#define x first
#define y second

void solve();
bool dfs(vector<plli> b, int i);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    vector<plli> a(3);
    for (auto& ai : a)
        cin >> ai.x >> ai.y;

    vector<vector<lli>> p3 = {{ 0LL, 1LL, 2LL },
                              { 0LL, 2LL, 1LL },
                              { 1LL, 0LL, 2LL },
                              { 1LL, 2LL, 0LL },
                              { 2LL, 0LL, 1LL },
                              { 2LL, 1LL, 0LL }};
    for (auto p : p3) {
        vector<plli> b(3);
        for (int i = 0; i < 3; ++i)
            b[i] = a[p[i]];
        if (dfs(b, 0)) {
            cout << "Sorry\n";
            return;
        }
    }
    cout << "Me\n";
}

bool dfs(vector<plli> b, int i) {
    if (i == 3) {
        if (b[0].x == b[1].x and b[1].x == b[2].x)
            return true;
        if (b[0].x == b[1].x and b[0].y + b[1].y == b[2].y)
            return true;
        return false;
    }
    bool res = dfs(b, i + 1);
    if (res)
        return true;
    swap(b[i].x, b[i].y);
    res = dfs(b, i + 1);
    return res;
}
