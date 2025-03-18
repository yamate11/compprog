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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [8o5OsZr8]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [8o5OsZr8]

  vector<ll> ans;

  auto report = [&]() -> void {
    cout << "Yes\n" << ssize(ans) << "\n";
    REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  };

  auto doswap = [&](ll i) -> void {
    ll x = A[i], y = A[i + 1];
    A[i] = y + K;
    A[i + 1] = x;
    ans.push_back(i);
  };

  auto f = [&](auto rF, ll start, ll size) -> void {
    assert(size >= 3);
    if (size == 3) {
      ll p0 = start, p1 = start + 1, p2 = start + 2;
      while (A[p0] > A[p1]) doswap(p1);
      doswap(p1);
      doswap(p0);
      while (not (A[p0] <= A[p1] and A[p1] <= A[p2])) doswap(p1);
      return;
    }
    rF(rF, start, size - 1);
    if (A[start + size - 2] > A[start + size - 1]) {
      REPrev(m, size - 2, 0) doswap(start + m);
      while (A[start] > A[start + 1]) {
        REP(i, 0, size - 1) REPrev(j, size - 2, 1) doswap(start + j);
      }
    }
  };

  if (N == 2) {
    if (A[0] <= A[1]) {
      report();
    }else {
      ans.push_back(0);
      if (A[1] + K <= A[0]) report();
      else cout << "No\n";
    }
    return 0;
  }
  f(f, 0, N);
  report();

  return 0;
}

