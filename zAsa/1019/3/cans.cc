#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

  ll t, N; cin >> t >> N;

  auto vec = vector(100 + t, false);
  REP(i, 0, 100) { vec[i * (100 + t) / 100] = true; }
  auto A = vector<ll>();
  REP(i, 0, 100 + t) if (not vec[i]) A.push_back(i);
  ll q = (N - 1) / t;
  ll r = (N - 1) % t;
  cout << (100 + t) * q + A[r] << endl;

  return 0;
}

