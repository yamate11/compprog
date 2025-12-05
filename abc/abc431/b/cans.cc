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

  ll X; cin >> X;
  ll N; cin >> N;
  // @InpVec(N, W) [J30up0lF]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [J30up0lF]
  vector<bool> pon(N, false);
  ll cur = X;
  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll p; cin >> p; p--;
    if (pon[p]) {
      pon[p] = false;
      cur -= W[p];
    }else {
      pon[p] = true;
      cur += W[p];
    }
    cout << cur << "\n";
  }

  return 0;
}

