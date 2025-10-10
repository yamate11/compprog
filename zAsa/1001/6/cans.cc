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
  string S, X; cin >> S >> X;

  vector<bool> vec_init(7, false);
  auto vec = vec_init;
  vec[0] = true; 
  REPrev(i, N - 1, 0) {
    auto prev = move(vec);
    vec = vec_init;
    REP(m, 0, 7) {
      if (X[i] == 'T') {
        if      (prev[(m * 10 + 0)            % 7]) vec[m] = true;
        else if (prev[(m * 10 + (S[i] - '0')) % 7]) vec[m] = true;
        else                                       vec[m] = false;
      }else if (X[i] == 'A') {
        if      (not prev[(m * 10 + 0)            % 7]) vec[m] = false;
        else if (not prev[(m * 10 + (S[i] - '0')) % 7]) vec[m] = false;
        else                                           vec[m] = true;
      }
    }
  }
  cout << (vec[0] ? "Takahashi\n" : "Aoki\n");

  return 0;
}

