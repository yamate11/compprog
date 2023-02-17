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

  auto ask = [&](ll t) -> ll {
    cout << t << endl;
    string s; cin >> s;
    if (s == "Vacant") return -1;
    if (s == "Male") return 0;
    if (s == "Female") return 1;
    assert(0);
  };

  ll N; cin >> N;

  ll lo = 0;
  ll hi = N;
  ll loC = ask(0);
  // ll hiC = loC;
  if (loC == -1) return 0;
  while (true) {
    ll mi = (lo + hi) / 2;
    ll miC = ask(mi);
    if (miC == -1) return 0;
    if ((loC == miC and (mi - lo - 1) % 2 == 0)
        or (loC != miC and (mi - lo - 1) % 2 != 0)) {
      hi = mi;
      // hiC = miC;
    }else {
      lo = mi;
      loC = miC;
    }
  }
  return 0;
}

