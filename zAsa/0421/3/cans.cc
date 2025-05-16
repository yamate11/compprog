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
  bool flipped = false;
  REP(_q, 0, Q) {
    ll t, a, b; cin >> t >> a >> b; a--; b--;
    if (t == 1) {
      if (flipped) {
        a = (N + a) % (2 * N);
        b = (N + b) % (2 * N);
      }
      swap(S[a], S[b]);
    }else if (t == 2) {
      flipped = not flipped;
    }else assert(0);
  }
  if (flipped) {
    cout << S.substr(N, N) << S.substr(0, N) << endl;
  }else {
    cout << S << endl;
  }

  return 0;
}

