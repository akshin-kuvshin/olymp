/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& a_i : a)
		cin >> a_i;
	cout << *max_element(a.begin(), a.end()) << '\n';
}
