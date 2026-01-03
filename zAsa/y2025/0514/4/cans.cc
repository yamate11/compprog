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
  vector<ll> vec(10);
  REP(i, 0, N) vec[S[i] - '0']++;
  ll ans = 0;
  for (ll i = 0; true; i++) {
    ll x = i * i;
    string t = to_string(x);
    if (ssize(t) > N) break;
    vector<ll> w(10);
    for (char cc : t) w[cc - '0']++;
    w[0] += N - ssize(t);
    if (vec == w) ans++;
  }
  cout << ans << endl;

  return 0;
}

