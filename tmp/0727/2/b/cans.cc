#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  ll pos = 0;
  REP(i, N) {
    string s; cin >> s;
    auto f = [&](ll d) -> ll {
      if (d < A) return A;
      if (d > B) return B;
      return d;
    };
    ll d; cin >> d;
    if (s == "East") pos += f(d);
    else pos -= f(d);
  }
  if (pos == 0) {
    cout << "0\n";
  }else if (pos > 0) {
    cout << "East " << pos << "\n";
  }else if (pos < 0) {
    cout << "West " << -pos << "\n";
  }

  return 0;
}

