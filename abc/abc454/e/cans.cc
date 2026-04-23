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

  auto solve = [&]() -> string {
    ll N, A, B; cin >> N >> A >> B; A--; B--;
    if (N % 2 != 0) return "";
    if ((A + B) % 2 == 0) return "";
    string ret = "";
    ll p = A / 2;
    REP(i, 0, p) ret += string(N - 1, 'R') + "D" + string(N - 1, 'L') + "D";
    ll q = B / 2;
    REP(i, 0, q) ret += "DRUR";
    if (A % 2 == 0) ret += "DR";
    else ret += "RD";
    REP(i, q + 1, N / 2) ret += "RURD";
    REP(i, p + 1, N / 2) ret += "D" + string(N - 1, 'L') + "D" + string(N - 1, 'R');
    return ret;
    
  };

  ll T; cin >> T;
  REP(t, 0, T) {
    string s = solve();
    if (ssize(s) == 0) cout << "No\n";
    else {
      cout << "Yes\n";
      cout << s << "\n";
    }
  }

  return 0;
}

