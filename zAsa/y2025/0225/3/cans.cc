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
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];
  auto f = [&](auto rF, ll n) -> ll {
    if (n == 0) return 1;
    string s; s = S[n - 1];
    ll t = rF(rF, n - 1);
    if (s == "AND") {
      return t;
    }else {
      return (1LL << n) + t;
    }
  };
  cout << f(f, N) << endl;

  return 0;
}

