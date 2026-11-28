// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

#define mp(_first, _second)     make_pair(_first, _second)

const int N = 3,
          KVANT = 20;
const vector<int> CPU_TIME  = {34, 47, 12},
                  DISK_TIME = {58, 25, 70};
const pi FREE = mp(-1, -1),
         SWITCH = mp(-1, 5);

int solve(const int T_MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int T_MAX = 1'000'000;
    cout << solve(T_MAX - 1) << ' ' << solve(T_MAX) << ' ' << solve(T_MAX + 1) << '\n';

    return 0;
}

int solve(const int T_MAX) {
    queue<pi> cpu_q;
    for (int i = 0; i < N; ++i)
        cpu_q.push(mp(i, CPU_TIME[i]));
    queue<int> disk_q;

    pi cpu = FREE,
       disk = FREE;
    int cpu_start = -1,
        cpu_last = 0;

    int downtime = 0;
    for (int t = 1; t <= T_MAX; ++t) {
        if (disk != FREE and disk.second == t) {
            cpu_q.push(mp(disk.first, CPU_TIME[disk.first]));
            disk = FREE;
        }

        if (cpu != FREE) {
            if (cpu.second == t) {
                if (cpu.first >= 0)
                    disk_q.push(cpu.first);
                cpu = FREE;
            } else if (t - cpu_start == KVANT) {
                cpu_q.push(mp(cpu.first, cpu.second - t));
                cpu = FREE;
            }
        }

        if (disk == FREE and not disk_q.empty()) {
            disk = mp(disk_q.front(), t + DISK_TIME[disk_q.front()]);
            disk_q.pop();
        }

        if (cpu == FREE) {
            if (not cpu_q.empty()) {
                if (cpu_q.front().first == cpu_last) {
                    cpu = mp(cpu_q.front().first, t + cpu_q.front().second);
                    cpu_q.pop();
                } else { // cpu_q.front().first != cpu_last
                    cpu = mp(SWITCH.first, t + SWITCH.second);
                    cpu_last = cpu_q.front().first;
                }
                cpu_start = t;
            } else // cpu_q.empty()
                ++downtime;
        }

        // cout << "t = " << t << " | cpu = " << cpu.first << " | disk = " << disk.first << '\n';
    }

    return downtime;
}
