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

  ll N, M; cin >> N >> M;
  vector<pll> C;
  REP(i, 0, N) {
    ll a; cin >> a;
    C.emplace_back(a, 0);
  }
  REP(i, 0, M) {
    ll b; cin >> b;
    C.emplace_back(b, 1);
  }
  sort(ALL(C));
  REP(i, 0, N + M - 1) {
    if (C[i].second == 0 and C[i + 1].second == 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

