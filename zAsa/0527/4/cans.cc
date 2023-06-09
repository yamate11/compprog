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

  ll N, A, B; cin >> N >> A >> B;
  ll sum = 0;
  ll vmax = LLONG_MIN;
  ll vmin = LLONG_MAX;
  REP(i, 0, N) {
    ll s; cin >> s;
    sum += s;
    vmax = max(vmax, s);
    vmin = min(vmin, s);
  }
  if (vmax == vmin) {
    cout << -1 << endl;
    return 0;
  }
  double P = double(B) / (vmax - vmin);
  double Q = A - P * sum / N;
  cout << P << " " << Q << endl;

  return 0;
}

