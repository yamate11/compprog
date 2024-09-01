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

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    // @InpVec(N, A) [C8JJZZiI]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [C8JJZZiI]
    // @InpVec(N, B) [IKmMOeAF]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [IKmMOeAF]

    vector<ll> fix, mob;
    REP(i, 0, N) {
      if (B[i]) mob.push_back(A[i]);
      else fix.push_back(A[i]);
    }
    sort(ALL(mob));
    sort(ALL(fix));
    ll z = (N - 1 + 1) / 2 - 1;
    if (mob.empty()) {
      cout << fix[N - 1] + fix[z] << "\n";
      return ;
    }
    vector<ll> tmp = fix;
    REP(i, 0, ssize(mob) - 1) tmp.push_back(mob[i]);
    sort(ALL(tmp));
    ll cand1;
    if (fix.empty() or fix.back() <= mob.back() + K) {
      cand1 = mob.back() + K + tmp[z];
    }else {
      cand1 = 0;
    }
    ll cand2;
    ll lim = 1e9;
    if (fix.empty() or (not mob.empty() and fix.back() <= mob.back())) {
      cand2 = 0;
    }else {
      vector<ll> S(ssize(mob) + 1);
      REP(i, 0, ssize(mob)) S[i + 1] = S[i] + mob[i];
      auto check = [&](ll th) -> bool {
        ll num1 = lower_bound(ALL(fix), th) - fix.begin();
        if (num1 > z) return false;
        ll allow = z - num1;
        ll bound = lower_bound(ALL(mob), th) - mob.begin();
        if (bound <= allow) return true;
        if (K >= th * (bound - allow) - (S[bound] - S[allow])) return true;
        return false;
      };
      ll med = binsearch<ll>(check, 0, lim + 1);
      cand2 = fix.back() + med;
    }
    ll ans = max(cand1, cand2);
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

