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

  ll N, Q, M; cin >> N >> Q >> M;
  // @InpVec(N, A) [BvxKZoFF]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [BvxKZoFF]
  string S; cin >> S;
  vector<bool> got(N, false);
  REP(m, 0, M) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll p; cin >> p; p--;
      char c; cin >> c;
      S[p] = c;
    }else if (tp == 2) {
      vector<ll> take;
      ll pos = 0;
      ll score = 0;
      for (char c : S) {
        if (c == 'L') {
          if (pos > 0) pos--;
        }else if (c == 'R') {
          if (pos <= N - 2) pos++;
        }else if (c == 'P') {
          if (not got[pos]) {
            got[pos] = true;
            take.push_back(pos);
            score += A[pos];
          }
        }else if (c == 'B') {
          pos = 0;
        }else assert(0);
      }
      cout << score << "\n";
      for (ll p : take) got[p] = false;
    }
  }

  return 0;
}

