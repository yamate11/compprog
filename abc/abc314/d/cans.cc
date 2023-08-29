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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  ll mode = 0;
  vector<ll> exact;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll t, x; cin >> t >> x; x--;
    char c; cin >> c;
    if (t == 1) {
      S[x] = c;
      exact.push_back(x);
    }else if (t == 2) {
      mode = 2;
      exact.resize(0);
    }else if (t == 3) {
      mode = 3;
      exact.resize(0);
    }else assert(0);
  }
  if (mode == 0) {
    ;
  }else {
    vector<bool> ex(N, false);
    for (ll p : exact) ex[p] = true;
    REP(i, 0, N) {
      if (ex[i]) continue;
      if (mode == 2) S[i] = tolower(S[i]);
      else S[i] = toupper(S[i]);
    }
  }
  cout << S << endl;

  return 0;
}

