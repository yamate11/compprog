#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/string>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

int main() {
  ll N; cin >> N;
  string S; cin >> S;
  auto sa = atcoder::suffix_array(S);
  auto lcp = atcoder::lcp_array(S, sa);

  ll ans = 0;
  REP(i, N - 1) {
    auto calc = [&](ll p, ll q, ll len) -> ll {
      if (len == 0) return 0;
      if (p > q) swap(p, q);
      if (p + len <= q) return len;
      ll period = q - p;
      ll n = len / period + 1;
      if (n % 2 == 0) return period * (n / 2);
      else return period * (n / 2) + (len % period); 
    };
    ans = max(ans, calc(sa[i], sa[i + 1], lcp[i]));
  }
  cout << ans << endl;

  return 0;
}

