/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
using namespace std;
typedef long long int lli;

void solve();
lli gcd_R(lli a, lli b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	lli m,
		n;
	cin >> m >> n;
	lli g = gcd_R(m, n);
	cout << g * g << '\n';
}

lli gcd_R(lli a, lli b) {
	return a && b ? gcd_R(b, a % b) : a | b;
}
