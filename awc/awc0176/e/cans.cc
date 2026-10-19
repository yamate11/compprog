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
// published at https://github.com/yamate11/compprog-clib/blob/master/binsearch.cc

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
  ll rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (ll r = 0; r < rep; r++) {
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

  ll N; cin >> N;
  // @InpVec(N, A) [44MiDVOl]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [44MiDVOl]
  // @InpVec(N, B) [fm1sQISy]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [fm1sQISy]

  auto A1 = A;
  auto B1 = B;
  ranges::sort(A1);
  ranges::sort(B1);
  auto f = [&]() -> ll {
    ll i = 0;
    REP(j, 0, N) {
      while (i < N and A1[i] <= B1[j]) i++;
      if (i == N) return j;
      i++;
    }
    return N;
  };
  ll nwin = f();
  
  ll e = B[N - 1];
  ll j0 = ranges::lower_bound(B1, e) - B1.begin();
  assert(B1[j0] == e);
  ll i0 = ranges::lower_bound(A1, e + 1) - A1.begin();
  
  auto g = [&](ll ii) -> ll {
    auto nxt = [&](ll i) -> ll {
      i++;
      if (i == ii) i++;
      return i;
    };

    ll ret = 0;
    ll i = 0;
    REP(j, 0, N) {
      if (j == j0) continue;
      while (i < N and A1[i] <= B1[j]) i = nxt(i);
      if (i == N) return ret;
      ret++;
      i = nxt(i);
    }
    return ret;
    
  };

  if (i0 < N) {

    auto check1 = [&](ll i1) -> bool {
      ll n = g(i1);
      return n == nwin - 1;
    };
    ll i1 = binsearch<ll>(check1, i0 - 1, N);
    
    if (i0 <= i1) {
      cout << nwin << " " << A1[i1] - e << "\n";
      return 0;
    }

  }

  auto check2 = [&](ll i2) -> bool {
    ll n = g(i2);
    return n == nwin;
  };
  ll i2 = binsearch<ll>(check2, -1, i0);
  cout << nwin << " " << A1[i2] - e << "\n";

  return 0;
}

