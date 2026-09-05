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
  string S; cin >> S;
  ll Q; cin >> Q;
  // @InpMVec(Q, (T, (X, dec=1), (C, type=char))) [mG0o5YKw]
  auto T = vector(Q, ll());
  auto X = vector(Q, ll());
  auto C = vector(Q, char());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; X[i] = v2;
    char v3; cin >> v3; C[i] = v3;
  }
  // @End [mG0o5YKw]

  ll last23 = -1;
  REPrev(i, Q - 1, 0) if (T[i] == 2 or T[i] == 3) { last23 = i; break; }
  REP(q, 0, Q) {
    if (T[q] == 1) {
      S[X[q]] = C[q];
    }else if (q == last23) {
      REP(i, 0, N) {
        if (T[q] == 2) {
          if ('A' <= S[i] and S[i] <= 'Z') S[i] = (S[i] - 'A') + 'a';
        }else {
          if ('a' <= S[i] and S[i] <= 'z') S[i] = (S[i] - 'a') + 'A';
        }
      }
    }
  }
  cout << S << "\n";

  return 0;
}

