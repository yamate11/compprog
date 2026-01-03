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

ll ask(ll i, ll j) {
  cout << "? " << i + 1 << " " << j + 1 << endl;
  ll x; cin >> x;
  return x;
}

ll report(ll d) {
  cout << "! " << d << endl;
  return 0;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll i0 = -1;
  ll vmax = 0;
  REP(i, 1, N) {
    ll v = ask(0, i);
    if (v > vmax) {
      vmax = v;
      i0 = i;
    }
  }
  ll diam = 0;
  REP(i, 0, N) {
    if (i == i0) continue;
    ll v = ask(i0, i);
    if (v > diam) diam = v;
  }
  report(diam);

  return 0;
}

