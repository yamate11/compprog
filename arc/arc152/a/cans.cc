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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, L; cin >> N >> L;
  // @InpVec(N, A) [bGa0wYVe]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [bGa0wYVe]
  ll f = 0;
  ll phase1 = true;
  REP(i, 0, N) {
    if (phase1) {
      if (A[i] == 1) {
        if (f + 2 <= L) f += 2;
        else phase1 = false;
      }else {
        if (f + 3 <= L) f += 3;
        else if (f + 2 == L) phase1 = false;
        else {
          cout << "No\n";
          return 0;
        }
      }
    }else {
      if (A[i] == 2) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}

