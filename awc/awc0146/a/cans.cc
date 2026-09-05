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

  ll N, M, Q; cin >> N >> M >> Q;
  // @InpMVec(N, ((S, dec=0), (U, dec=0), (F, dec=0))) [kTZC5dQL]
  auto S = vector(N, ll());
  auto U = vector(N, ll());
  auto F = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 0; S[i] = v1;
    ll v2; cin >> v2; v2 -= 0; U[i] = v2;
    ll v3; cin >> v3; v3 -= 0; F[i] = v3;
  }
  // @End [kTZC5dQL]
  
  REP(q, 0, Q) {
    ll d; cin >> d; d--;
    char c; cin >> c;
    ll u = U[d];
    ll f = F[d];
    if (c == '+') {
      S[d] += 1;
      U[d] = 7 - f;
      F[d] = u;
    }else {
      S[d] -= 1;
      U[d] = f;
      F[d] = 7 - u;
    }
  }
  REP(i, 0, N) {
    cout << S[i] << " " << U[i] << "\n";
  }



  return 0;
}

