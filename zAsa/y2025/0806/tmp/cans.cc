#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(f:perfmeas)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

struct SafeHash {
    // 64bit ミキサ（splitmix64 相当）
    static uint64_t mix(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(const string& s) const {
        static const uint64_t seed =
            chrono::steady_clock::now().time_since_epoch().count();
        // 8バイトずつ取り込んで mix。末尾はゼロ詰め。
        uint64_t h = seed ^ 0x9e3779b97f4a7c15ULL;
        const unsigned char* p = (const unsigned char*)s.data();
        size_t n = s.size();
        while (n >= 8) {
            uint64_t v;
            memcpy(&v, p, 8);
            h = mix(h ^ v);
            p += 8; n -= 8;
        }
        uint64_t tail = 0;
        for (size_t i = 0; i < n; ++i) tail |= uint64_t(p[i]) << (8*i);
        h = mix(h ^ tail);
        return (size_t)h;
    }
};

template<class T>
using umap_s = unordered_map<string, T, SafeHash>;

/*
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

    umap_s<int> mp;
    mp.reserve(1<<20);                 // 期待件数に合わせて余裕をとる
    mp.max_load_factor(0.7f);          // チェイン長を抑える
    // 使い方は普通の unordered_map と同じ
}
*/

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  umap_s<ll> mp;
  // unordered_map<string, ll> mp;
  // mp.reserve((ll)(1<<20));

  ll N; cin >> N;
  // ll x = 0;
  double t0 = get_time_sec();
  REP(i, 0, N) {
    string s; cin >> s;
    // x += ssize(s);
    mp[s]++;
  }
  double t1 = get_time_sec();
  cout << t1 - t0 << endl;

  return 0;
}
