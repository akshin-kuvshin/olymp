/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
using namespace std;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	int n,
		m,
		k;
	cin >> n >> m >> k;
    int tmp;
	for (int _ = 0; _ < m; ++_)
		cin >> tmp >> tmp;
	cout << ((k * n) % 2 == 0 ? "YES" : "NO") << '\n';
}
