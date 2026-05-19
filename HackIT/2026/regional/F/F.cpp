/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;
#define pb push_back

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
    vector<lli> arr(n),
                go(n - 1LL),
                drg(n - 1LL);
    for (auto& arr_i : arr)
        cin >> arr_i;
    for (auto& go_i : go)
        cin >> go_i;
    for (auto& drg_i : drg)
        cin >> drg_i;

    lli f;
    cin>>f;
    vector<lli> dragon = {f};
    for (int i = (int)n - 2; i >= 0; --i)
        dragon.pb(dragon.back() + drg[i]);

    reverse(dragon.begin(), dragon.end());
    pair<lli, lli> ans = {-1LL, 0LL};
    lli l = n - 1LL,
        r = n - 1LL;
    lli tml = 0LL,
        tmr = 0LL;
    lli ar = arr.back();

    for (int i = (int)n - 1; i >= 0; --i) {
        lli tm = dragon[i];
        while (true) {
            if (tmr > tm) {
                --r;
                tmr -= go[r];
                ar -= arr[r + 1LL];
            } else if (tml < tm and l > 0LL) {
                --l;
                tml += go[l];
                ar += arr[l];
                if (tml > tm) {
                    tml -= go[l];
                    ar -= arr[l];
                    ++l;
                    break;
                }
            } else
                break;
        }

        tmr += go[i - 1];
        if (l != 0)
            tml -= go[i - 1];
        if (ans.first < ar)
            ans = {ar, (lli)(i + 1)};
    }

    cout << ans.first << ' ' << ans.second << '\n';
}
