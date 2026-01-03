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

  auto g = [&](const auto& P) -> ll {
    ll M = ssize(P);
    vector<ll> A(M + 1);
    REP(i, 0, M) A[i + 1] = A[i] + P[i];
    ll ret = 0;
    REP(i, 0, M) {
      ret += A[M] - A[i] - (M - i - 1) * P[i];
    }
    return ret;
  };

  auto f = [&](auto& P) -> ll {
    ranges::sort(P);
    ll a = g(P);
    ranges::reverse(P);
    for (ll& p : P) p = -p;
    ll b = g(P);
    return a + b;
  };


  ll N; cin >> N;
  // @InpMVec(N, (X, Y)) [hAkEKjAN]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [hAkEKjAN]

  vector<ll> P0, Q0, P1, Q1;
  REP(i, 0, N) {
    if ((X[i] + Y[i]) % 2 == 0) {
      P0.push_back((X[i] + Y[i]) / 2);
      Q0.push_back((X[i] - Y[i]) / 2);
    }else {
      P1.push_back((X[i] + Y[i] - 1) / 2);
      Q1.push_back((X[i] - Y[i] - 1) / 2);
    }
  }
  cout << (f(P0) + f(Q0) + f(P1) + f(Q1)) / 2 << endl;

  return 0;
}

