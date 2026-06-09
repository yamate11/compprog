#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using pll = pair<ll, ll>;

  auto solve = [&]() -> bool {
    ll N, M; cin >> N >> M;
    vector<pll> A;
    REP(i, N) {
      ll a; cin >> a;
      A.emplace_back(a, 1);
    }
    ll K; cin >> K;
    vector<pll> B;
    REP(i, K) {
      ll b; cin >> b;
      B.emplace_back(b, 1);
    }
    while (true) {
      if (A.empty() and B.empty()) return true;
      if (A.empty() or B.empty()) return false;
      auto [a, na] = A.back(); A.pop_back();
      auto [b, nb] = B.back(); B.pop_back();
      if (a == b) {
        if (na < nb) { B.emplace_back(b, nb - na); }
        else if (na > nb) { A.emplace_back(a, na - nb); }
      }else {
        if (a > b) { swap(a, b); swap(na, nb); swap(A, B); }
        ll p = 1;
        while (a * p < b) p *= M;
        if (a * p > b) return false;
        A.emplace_back(a, na);
        B.emplace_back(a, nb * p);
      }
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

