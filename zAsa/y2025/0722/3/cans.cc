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

// @@ !! LIM(binsearch)

// ---- inserted library file binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err, const bool abs_only = false) {
  T rep_in_t = ceil(log(abs(yes - no) / err) / log(2.0));
  constexpr int lim = INT_MAX - 10;
  int rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (not abs_only) {
      if (abs(yes - mid) < err * min(abs(mid), abs(yes))) return mid;
    }
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(N, L) [8qVbQCa5]
  auto L = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; L[i] = v; }
  // @End [8qVbQCa5]

  ll big = 1e18;
  auto check = [&](ll w) -> bool {
    auto fill = [&](ll idx) -> ll {
      ll len = 0;
      ll cnt = 0;
      for ( ; idx + cnt < N; cnt++) {
        ll new_len = len + L[idx + cnt] + (cnt == 0 ? 0 : 1);
        if (new_len > w) return cnt;
        len = new_len;
      }
      return cnt;
    };
    ll idx = 0;
    REP(i, 0, M) {
      ll cnt = fill(idx);
      if (cnt == 0) return false;
      idx += cnt;
      if (idx == N) return true;
    }
    return false;
  };
  ll w = binsearch<ll>(check, big, 0);
  cout << w << endl;

  return 0;
}

