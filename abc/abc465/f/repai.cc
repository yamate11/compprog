#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
long long f[MAXN];          // 前缀和数组
int pow10[6] = {100000, 10000, 1000, 100, 10, 1};

double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double t0 = get_time_sec();
    int N;
    cin >> N;

    string s;
    long long v;
    for (int i = 0; i < N; ++i) {
        cin >> s >> v;
        int id = 0;
        for (int k = 0; k < 6; ++k) {
            id = id * 10 + (s[k] - '0');
        }
        f[id] += v;          // 同一个 ID 只出现一次，直接赋值也可
    }
    int Q;
    cin >> Q;
    /*
    vector<string> X(Q), Y(Q);
    for (int q = 0; q < Q; q++) {
      cin >> X[q];
      cin >> Y[q];
    }
    */

    double t1 = get_time_sec();

    // 6 维前缀和
    for (int dim = 0; dim < 6; ++dim) {
        int w = pow10[dim];  // 当前维度的权值
        for (int idx = 0; idx < MAXN; ++idx) {
            int digit = (idx / w) % 10;
            if (digit > 0) {
                f[idx] += f[idx - w];
            }
        }
    }

    double t2 = get_time_sec();
    long long checksum = 0;
    // while (Q--) {
    for (int q = 0; q < Q; q++) {
      /*
        string& x = X[q];
        string& y = Y[q];
      */
        string x, y; cin >> x >> y;

        // 检查是否存在 x_k > y_k
        bool ok = true;
        for (int k = 0; k < 6; ++k) {
            if (x[k] > y[k]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << 0 << '\n';
            continue;
        }

        long long ans = 0;
        // 容斥枚举 64 种边界组合
        for (int mask = 0; mask < 64; ++mask) {
            int bits = __builtin_popcount(mask);
            long long sign = (bits & 1) ? -1 : 1;
            int idx = 0;
            bool skip = false;

            for (int k = 0; k < 6; ++k) {
                int digit;
                if (mask & (1 << k)) {
                    // 取下界 x_k - 1
                    digit = x[k] - '0' - 1;
                    if (digit < 0) {
                        skip = true;
                        break;
                    }
                } else {
                    // 取上界 y_k
                    digit = y[k] - '0';
                }
                idx = idx * 10 + digit;
            }

            if (skip) continue;
            ans += sign * f[idx];
        }
        // cout << ans << '\n';
        checksum ^= ans;
    }
    double t3 = get_time_sec();
    cerr << "time: " << t1 - t0 << endl;
    cerr << "time: " << t2 - t1 << endl;
    cerr << "time: " << t3 - t2 << endl;
    cerr << "checksum = " << checksum << endl;

    return 0;
}
