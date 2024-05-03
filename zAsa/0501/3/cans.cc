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
  auto f = [&](ll x) -> ll {
    if (x < N) return x + N;
    else return x - N;
  };
  REP(_q, 0, Q) {
    ll tp ; cin >> tp;
    ll a, b; cin >> a >> b; a--; b--;
    if (tp == 1) {
      if (flipped) {
        a = f(a);
        b = f(b);
        swap(S[a], S[b]);
      }else {
        swap(S[a], S[b]);
      }
    }else if (tp == 2) {
      flipped = not flipped;
    }else assert(0);
  }
  if (flipped) {
    REP(i, 0, N) swap(S[i], S[i + N]);
  }
  cout << S << endl;


  return 0;
}

