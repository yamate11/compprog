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

ll ask(ll i) {
  cout << "? " << i + 1 << endl;
  ll x; cin >> x;
  return x;
}

void fin(ll i) {
  cout << "! " << (i >= 0 ? i + 1 : -1) << endl;
  exit(0);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, x; cin >> N >> x;
  ll lo = -1, hi = N;
  while (true) {
    if (lo + 1 == hi) fin(-1);
    ll mid = (lo + hi) / 2;
    ll y = ask(mid);
    if      (y < x)  lo = mid;
    else if (x < y)  hi = mid;
    else if (x == y) fin(mid);
  }

  return 0;
}

