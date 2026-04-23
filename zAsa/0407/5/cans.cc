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

  ll N, C; cin >> N >> C;

  auto func = [&](const auto& dist, const auto& val) -> ll {
    vector<ll> H(N);
    H[N - 1] = val[N - 1] - (C - dist[N - 1]);
    REPrev(i, N - 2, 0) H[i] = H[i + 1] + val[i] - (dist[i + 1] - dist[i]);
    ll ret1 = *ranges::max_element(H);

    vector<ll> G(N);
    G[0] = val[0] - dist[0];
    REP(i, 1, N) {
      G[i] = G[i - 1] + val[i] - (dist[i] - dist[i - 1]);
    }
    REP(i, 1, N) G[i] = max(G[i], G[i - 1]);

    ll ret2 = 0;
    REPrev(i, N - 1, 1) {
      ret2 = max(ret2, H[i] - (C - dist[i]) + G[i - 1]);
    }
    return max(ret1, ret2);
  };



  // @InpMVec(N, (X, V)) [eEcXtLh3]
  auto X = vector(N, ll());
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; V[i] = v2;
  }
  // @End [eEcXtLh3]

  ll a1 = func(X, V);
  vector<ll> Y(N);
  vector<ll> W(N);
  REP(i, 0, N) {
    Y[N - 1 - i] = C - X[i];
    W[N - 1 - i] = V[i];
  }
  ll a2 = func(Y, W);
  cout << max(a1, a2) << endl;

  return 0;
}

