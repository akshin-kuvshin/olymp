// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

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
    string s,
           t;
    cin >> s >> t;

    for (int i = 0; i < (int)n; ++i)
        if (t[i] != '*' and s[i] != t[i]) {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}
