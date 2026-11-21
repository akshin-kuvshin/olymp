/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
#include <vector>
using namespace std;

#define pb(elem_)				push_back(elem_)

void solve();
void dfs(int v, const vector<vector<int>>& G, vector<bool>& used, int& leaves);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	int n,
		m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	while (m--) {
		int u,
			v;
		cin >> u >> v;
		--u; --v;
		G[u].pb(v);
		G[v].pb(u);
	}

	int ans = 0;
	vector<bool> used(n);
	for (int v = 0; v < n; ++v) {
		if (used[v])
			continue;
		if (G[v].empty()) {
			++ans;
			continue;
		}
		int leaves = 0;
		dfs(v, G, used, leaves);
		ans += (leaves + 1) / 2;
	}

	cout << ans << '\n';
}

void dfs(int v, const vector<vector<int>>& G, vector<bool>& used, int& leaves) {
	used[v] = true;
	leaves += (int)G[v].size() == 1;
	for (auto nb : G[v]) {
		if (used[nb])
			continue;
		dfs(nb, G, used, leaves);
	}
}
