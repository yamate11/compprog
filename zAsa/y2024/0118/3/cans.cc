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

  ll N; cin >> N;
  // @InpMVec(N, (X, Y)) [eOFpKsYY]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [eOFpKsYY]

  vector xord(N, 0LL), yord(N, 0LL);
  REP(i, 0, N) {
    xord[i] = i;
    yord[i] = i;
  }
  sort(ALL(xord), [&](ll i, ll j) -> bool { return X[i] < X[j]; });
  sort(ALL(yord), [&](ll i, ll j) -> bool { return Y[i] < Y[j]; });
  set<tuple<ll, ll, ll>> ss;
  auto f = [&](const auto& vec, const auto& ord, ll b, ll e) -> void {
    ll i = ord[b];
    ll j = ord[e];
    ss.emplace(vec[j] - vec[i], i, j);
  };

  f(X, xord, 0, N - 1);
  f(X, xord, 1, N - 1);
  f(X, xord, 0, N - 2);
  f(Y, yord, 0, N - 1);
  f(Y, yord, 1, N - 1);
  f(Y, yord, 0, N - 2);
  auto it = ss.end();
  it--;
  it--;
  auto [d, i, j] = *it;
  cout << d << endl;
  


  return 0;
}

