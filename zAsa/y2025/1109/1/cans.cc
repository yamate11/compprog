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
  string s; cin >> s;
  string ans;
  ll cnt = 0;
  REP(i, 0, N + 1) {
    if (i == N or s[i] == 'C') {
      ll p = cnt / 2;
      ll q = cnt % 2;
      ans += string(p, 'A');
      if (q) ans += "B";
      if (i == N) break;
      ans += "C";
      cnt = 0;
    }else if (s[i] == 'A') {
      cnt += 2;
    }else if (s[i] == 'B') {
      cnt += 1;
    }else assert(0);
  }
  cout << ans << endl;

  return 0;
}

