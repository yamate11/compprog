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

  ll N, M; cin >> N >> M;
  ll lim = 1e9;
  if (N == 1) {
    ll s = N * (M + 1);
    if (s > lim) {
      cout << "inf\n";
    }else {
      cout << s << "\n";
    }
  }else {
    ll s = 0;
    ll a = 1;
    REP(i, 0, M + 1) {
      if (s + a > lim) {
        cout << "inf\n";
        return 0;
      }
      s += a;
      if (a * N > lim) {
        a = lim + 1;
      }else {
        a *= N;
      }
    }
    cout << s << endl;
  }

  return 0;
}

