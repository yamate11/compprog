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

  ll N; cin >> N;
  // @InpVec(N + 1, A) [3i9RjJ3S]
  auto A = vector(N + 1, ll());
  for (int i = 0; i < N + 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [3i9RjJ3S]

  ll nnd = 0;
  ll t = 0;
  REP(i, 1, N + 1) {
    nnd += A[i];
    t += i * A[i];
  }
  if (t == 0) {
    cout << "Yes\n";
    return 0;
  }
  if (t % 2 != 0) {
    if (N % 2 == 0) {
      A.push_back(1);
      t += N + 1;
    }else {
      A.push_back(0);
      A.push_back(1);
      t += N + 2;
    }
  }
  ll e = t / 2;
  if (e <= nnd - 1) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

