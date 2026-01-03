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
  auto T = vector(0, ll());
  auto X = vector(0, ll());
  auto Y = vector(0, ll());
  T.push_back(0);
  X.push_back(0);
  Y.push_back(0);
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; T.push_back(v1);
    ll v2; cin >> v2; X.push_back(v2);
    ll v3; cin >> v3; Y.push_back(v3);
  }
  REP(i, 0, N) {
    ll dt = T[i + 1] - T[i];
    ll dx = X[i + 1] - X[i];
    ll dy = Y[i + 1] - Y[i];
    ll d = abs(dx) + abs(dy);
    if (d <= dt and (dt - d) % 2 == 0) ;
    else {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";


  return 0;
}

