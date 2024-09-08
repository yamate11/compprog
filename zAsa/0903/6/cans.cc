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

  ll N, X; cin >> N >> X;
  // @InpVec(N, T) [12obkjyI]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [12obkjyI]
  // @InpVec(N, A) [mHLMAr8T]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mHLMAr8T]

  ll allA = accumulate(ALL(A), 0LL);
  if (allA < X) {
    cout << -1 << endl;
    return 0;
  }

  vector TA(N, pll());
  REP(i, 0, N) TA[i] = pll(T[i], A[i]);
  sort(ALL(TA));
  auto check = [&](ll limit) -> bool {
    ll prev_t = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pque;
    ll tot = 0;
    for (auto [t, a] : TA) {
      while (prev_t < t and prev_t < limit) {
        pque.push(0);
        prev_t++;
      }
      if (a > pque.top()) {
        tot += a - pque.top();
        pque.pop();
        pque.push(a);
      }
    }
    return tot >= X;
  };

  ll big = 2e5;
  ll lim = binsearch<ll>(check, big, 0);
  if (lim == big) lim = -1;
  else lim = lim + 0;
  cout << lim  << endl;

  return 0;
}

