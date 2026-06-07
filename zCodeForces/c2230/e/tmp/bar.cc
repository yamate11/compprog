#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class F>
double bench(const string& name, F f) {
    auto st = chrono::high_resolution_clock::now();

    volatile ll res = f(); // 最適化で消されるのを防ぐ

    auto ed = chrono::high_resolution_clock::now();
    double ms = chrono::duration<double, milli>(ed - st).count();

    cout << name << ": " << ms << " ms, res = " << res << '\n';
    return ms;
}

int main() {
    constexpr int N = 2000000;
    constexpr int LOOP = 50; // N * LOOP = 1e8

    bench("vector resize + index write", [&]() -> ll {
        ll s = 0;
        vector<int> v;

        for (int r = 0; r < LOOP; r++) {
            v.resize(N);

            for (int i = 0; i < N; i++) {
                v[i] = i;
            }

            if (r == LOOP - 1) {
                for (int i = 0; i < N; i++) {
                    s += v[i];
                }
            }
        }

        return s;
    });

    bench("vector assign + index write", [&]() -> ll {
        ll s = 0;
        vector<int> v;

        for (int r = 0; r < LOOP; r++) {
            v.assign(N, 0);

            for (int i = 0; i < N; i++) {
                v[i] = i;
            }

            if (r == LOOP - 1) {
                for (int i = 0; i < N; i++) {
                    s += v[i];
                }
            }
        }

        return s;
    });

    bench("vector reserve + push_back", [&]() -> ll {
        ll s = 0;
        vector<int> v;
        v.reserve(N);

        for (int r = 0; r < LOOP; r++) {
          // v.clear();
          v.resize(0);

            for (int i = 0; i < N; i++) {
                v.push_back(i);
            }

            if (r == LOOP - 1) {
                for (int i = 0; i < N; i++) {
                    s += v[i];
                }
            }
        }

        return s;
    });

    bench("vector push_back without reserve", [&]() -> ll {
        ll s = 0;

        for (int r = 0; r < LOOP; r++) {
            vector<int> v;

            for (int i = 0; i < N; i++) {
                v.push_back(i);
            }

            if (r == LOOP - 1) {
                for (int i = 0; i < N; i++) {
                    s += v[i];
                }
            }
        }

        return s;
    });
}
