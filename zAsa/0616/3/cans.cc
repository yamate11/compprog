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

  auto judge = [&](auto rF, string s) -> ll {
    ll n = SIZE(s);
    if (n == 0) {
      return -1;
    }else if (n == 1) {
      if (s == "b") return 0;
      else return -1;
    }else if (s[0] == 'a' and s.back() == 'c') {
      ll m = rF(rF, s.substr(1, n - 2));
      if (m < 0) return m;
      m++;
      if (m % 3 == 1) return m;
      else return -1;
    }else if (s[0] == 'c' and s.back() == 'a') {
      ll m = rF(rF, s.substr(1, n - 2));
      if (m < 0) return m;
      m++;
      if (m % 3 == 2) return m;
      else return -1;
    }else if (s[0] == 'b' and s.back() == 'b') {
      ll m = rF(rF, s.substr(1, n - 2));
      if (m < 0) return m;
      m++;
      if (m % 3 == 0) return m;
      else return -1;
    }else return -1;
  };
  ll N; cin >> N;
  string S; cin >> S;
  cout << judge(judge, S) << endl;

  return 0;
}

