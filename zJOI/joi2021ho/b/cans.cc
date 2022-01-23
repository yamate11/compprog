// #undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
// #pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
// #pragma GCC target("movbe")                                      // byte swap
// #pragma GCC target("aes,pclmul,rdrnd")                           // encryption
// #pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD

#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double t1 = get_time_sec();

  ll N, Q; cin >> N >> Q;
  vector<ll> X(N);
  for (ll i = 0; i < N; i++) cin >> X[i];

  double t2 = get_time_sec();


  using sta = pair<ll, ll>;
  ll big = 1e18;
  vector<sta> rec({{big, 0}, {big, N}});
  for (ll i = 1; i < N; i++) rec.emplace_back(X[i] - X[i-1], i);
  sort(rec.begin(), rec.end());
  vector<ll> bound({0, 0});
  ll pos = 0;
  ll sidx = 0;
  vector<ll> ans(N);

  auto op = [&](ll me, ll you, ll newbnd) -> void {
    if (newbnd <= bound[me]) return;
    bound[me] = newbnd;
    ll bnd = bound[0] + bound[1];
    ll p = upper_bound(rec.begin(), rec.end(), sta(bnd, -1)) - rec.begin();
    for (ll j = sidx; j < p; j++) {
      auto [v, i] = rec[j];
      ans[i-1+you] += bound[you];
      ans[i-1+me]  += v - bound[you];
    }
    sidx = p;
  };

  for (; Q > 0; Q--) {
    ll w; cin >> w;
    pos += w;
    op(0, 1, pos);
    op(1, 0, -pos);
  }
  for (ll j = sidx; j <= N; j++) {
    auto [v, i] = rec[j];
    if (i-1 >= 0) ans[i-1] += bound[0];
    if (i < N)    ans[i]   += bound[1];
  }

  double t3 = get_time_sec();

  for (ll i = 0; i < N; i++) cout << ans[i] << "\n";

  double t4 = get_time_sec();

  cerr << t2 - t1 << "\n";
  cerr << t3 - t2 << "\n";
  cerr << t4 - t3 << "\n";

  return 0;
}

