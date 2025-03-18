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

  // @InpVec(3, S, type=char) [jr7Dio2V]
  auto S = vector(3, char());
  for (int i = 0; i < 3; i++) { char v; cin >> v; S[i] = v; }
  // @End [jr7Dio2V]
  // @InpVec(3, T, type=char) [3sZPriKK]
  auto T = vector(3, char());
  for (int i = 0; i < 3; i++) { char v; cin >> v; T[i] = v; }
  // @End [3sZPriKK]

  auto f = [&](const auto& v) -> ll {
    vector<ll> u(3);
    REP(i, 0, 3) {
      if (v[i] == 'R') u[i] = 0;
      else if (v[i] == 'G') u[i] = 1;
      else if (v[i] == 'B') u[i] = 2;
      else assert(0);
    }
    ll t = 0;
    REP(i, 0, 3) REP(j, i + 1, 3) if (u[i] > u[j]) t++;
    return t;
  };

  ll x = f(S);
  ll y = f(T);
  cout << ((x - y) % 2 == 0 ? "Yes\n" : "No\n") << endl;

  return 0;
}

