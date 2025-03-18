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

  ll N; cin >> N;
  string S; cin >> S;

  auto f = [&](bool a, bool b) -> bool {
    vector<bool> vec(N + 2);
    vec[0] = a;
    vec[1] = b;
    REP(i, 2, N + 2) {
      vec[i] = vec[i - 2] ^ vec[i - 1] ^ (S[(i - 1) % N] == 'x');
    }
    if (vec[0] == vec[N] and vec[1] == vec[N + 1]) {
      string ans(N, ' ');
      REP(i, 0, N) ans[i] = vec[i] ? 'W' : 'S';
      cout << ans << endl;
      return true;
    }else {
      return false;
    }
  };

  if (
      f(true, true) or
      f(true, false) or
      f(false, true) or
      f(false, false)) {
  }else {
    cout << -1 << endl;
  }

  return 0;
}

