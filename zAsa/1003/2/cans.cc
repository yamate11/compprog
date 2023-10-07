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
  ll p = 0;
  REP(i, 0, N) {
    string s; cin >> s;
    ll d; cin >> d;
    if (d <= A) d = A;
    if (d >= B) d = B;
    if (s == "West") d = -d;
    p += d;
  }
  if (p == 0) cout << 0 << endl;
  else if (p > 0) cout << "East" << " " << p << endl;
  else cout << "West" << " " << -p << endl;

  return 0;
}

