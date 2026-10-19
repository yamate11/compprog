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

  ll Q; cin >> Q;
  string S, T; cin >> S >> T;
  ll N = ssize(S);
  ll M = ssize(T);
  vector<ll> poss;
  REP(i, 0, N - M + 1) if (S.substr(i, M) == T) poss.push_back(i);
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    ll k = ranges::lower_bound(poss, l) - poss.begin();
    if (k < ssize(poss) and poss[k] + M <= r) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
  }

  return 0;
}

