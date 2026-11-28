/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

#define pb(elem_)				push_back(elem_)
#define mp(first_, second_)		make_pair(first_, second_)

struct Node {
	pi p;
	bool fire;
	int d = -1;
};

void solve();
vector<pi> get_ns(int x, int y);

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
	vector<vector<char>> a(n + 2, vector<char>(m + 2, '#'));
	pi start,
	   end;
	vector<pi> fires;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'S')
				start = mp(i, j);
			else if (a[i][j] == 'E')
				end = mp(i, j);
			else if (a[i][j] == 'F')
				fires.pb(mp(i, j));
		}

	queue<Node> q;
	q.push({ start, false, 0 });
	for (auto p : fires)
		q.push({ .p = p, .fire = true });
	while (not q.empty()) {
		auto [p, fire, d] = q.front();
		q.pop();
		auto [x, y] = p;

		if (not fire) {
			if (a[x][y] == 'F')
				continue;
			++d;
			for (auto [nx, ny] : get_ns(x, y)) {
				if (a[nx][ny] == 'E') {
					cout << d << '\n';
					return;
				}
				if (a[nx][ny] != '.')
					continue;
				a[nx][ny] = 'S';
				q.push({ mp(nx, ny), false, d });
			}
		} else { // fire
			for (auto [nx, ny] : get_ns(x, y)) {
				if (a[nx][ny] == 'E') {
					cout << "-1\n";
					return;
				}
				if (a[nx][ny] == '#' or a[nx][ny] == 'F')
					continue;
				a[nx][ny] = 'F';
				q.push({ .p = mp(nx, ny), .fire = true });
			}
		}
	}
	cout << "-1\n";
}

vector<pi> get_ns(int x, int y) {
	return { {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1} };
}
