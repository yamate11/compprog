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

  ll N, K; cin >> N >> K;
  set<ll> ss;
  REP(i, 0, N) {
    ll a; cin >> a;
    ll b = a % K;
    ss.insert(b);
  }
  vector<ll> vec;
  for (ll s : ss) vec.push_back(s);
  if (ssize(ss) == 1) {
    cout << 0 << endl;
    return 0;
  }
  vec.push_back(vec[0] + K);
  ll v = 0;
  REP(i, 0, ssize(vec) - 1) {
    v = max(v, vec[i + 1] - vec[i]);
  }
  cout << K - v << endl;

  return 0;
}

