#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  ll P, Q, R, S; cin >> P >> Q >> R >> S;

  vector b(Q - P + 1, vector(S - R + 1, 0));

  auto f1 = [&]() -> void {
    ll alpha = max(1 - A, 1 - B);
    ll beta = min(N - A, N - B);
    REP2(i, P, Q + 1) {
      ll k = i - A;
      if (not (alpha <= k and k <= beta)) continue;
      ll j = i - A + B;
      if (not (R <= j and j <= S)) continue;
      b[i - P][j - R] = 1;
    }
  };
  auto f2 = [&]() -> void {
    ll alpha = max(1 - A, B - N);
    ll beta = min(N - A, B - 1);
    REP2(i, P, Q + 1) {
      ll k = i - A;
      if (not (alpha <= k and k <= beta)) continue;
      ll j = A - i + B;
      if (not (R <= j and j <= S)) continue;
      b[i - P][j - R] = 1;
    }
  };

  f1();
  f2();

  REP(i, Q - P + 1) {
    REP(j, S - R + 1) {
      if (b[i][j]) cout << "#";
      else cout << ".";
    }
    cout << "\n";
  }

  return 0;
}

