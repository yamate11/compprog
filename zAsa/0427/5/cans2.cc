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

  ll N, Q; cin >> N >> Q;
  string S; cin >> S;
  vector<ll> pos1, pos2;
  vector<ll> accSlush(N + 1, 0LL);
  REP(i, 0, N) {
    if (S[i] == '1') pos1.push_back(i);
    if (S[i] == '2') pos2.push_back(i);
    accSlush[i + 1] = accSlush[i] + (S[i] == '/' ? 1 : 0);
  }
  
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    ll ans;
    if (accSlush[r] == accSlush[l]) ans = 0;
    else {
      auto check = [&](ll m) -> bool {
        ll i0 = ranges::lower_bound(pos1, l) - pos1.begin();
        if (i0 + m - 1 >= ssize(pos1)) return false;
        ll l0 = pos1[i0 + m - 1] + 1;
        ll j0 = ranges::lower_bound(pos2, r) - pos2.begin();
        if (j0 - m < 0) return false;
        ll r0 = pos2[j0 - m];
        return accSlush[r0] > accSlush[l0];
      };
      ll m = binsearch<ll>(check, 0, r - l);
      ans = 2 * m + 1;
    }
    cout << ans << "\n";
  }


  return 0;
}

