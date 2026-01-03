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

  auto f = [&](string& t) -> vector<bool> {
    vector<bool> ret(26);
    for (char c : t) {
      ret[c - 'a'] = true;
    }
    return ret;
  };


  ll N; cin >> N;
  string S; cin >> S;
  ll ans = 0;
  REP(len, 1, N) {
    string a = S.substr(0, len);
    string b = S.substr(len);
    auto u = f(a);
    auto v = f(b);
    ll cur = 0;
    REP(i, 0, 26) {
      if (u[i] and v[i]) cur++;
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;

  return 0;
}

