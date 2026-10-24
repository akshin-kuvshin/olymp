/* authors:
1) Danila "akshin_" Axyonov;
2) Alexander "Valeev_Alex" Valeev;
3) Nikita "benchik_228" Terebinov.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long int lli;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    string s;
    cin >> s;
    s = '(' + s + ')';
    lli n = (lli)s.size();

    stack<lli> st;
    lli ans = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        if (s[i] == '(') {
            if (not st.empty()) {
                ++st.top();
                st.push(1LL);
            } else // st.empty()
                st.push(0LL);
        } else { // s[i] == ')'
            ans = max(ans, st.top());
            st.pop();
        }
    }

    cout << ans << '\n';
}
