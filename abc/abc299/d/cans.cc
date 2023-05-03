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
  cout << "? " << i + 1 << endl;   // 0-index 等はここで調整
  ll x; cin >> x;
  return x;
}

void fin(ll i) {
  cout << "! " << i + 1 << endl;
  exit(0);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll lo = 0, hi = N - 1;
  while (true) {
    if (lo + 1 == hi) {
      fin(lo);
    }
    ll mid = (lo + hi) / 2;
    if (ask(mid) == 0) {
      lo = mid;
    }else {
      hi = mid;
    }
  }
  return 0;
}

