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

  set<ll> ss;
  ss.insert(2);
  ss.insert(3);
  ss.insert(6);
  vector P(501, vector<ll>());
  P[3] = vector<ll>{2, 3, 6};
  ll lim = 1e9;
  while (true) {
    ll b = false;
    for (ll x : ss) {
      ll y = x * (x + 1);
      if (y > lim) break;
      if (not ss.contains(x + 1) and not ss.contains(y)) {
        b = true;
        ss.erase(x);
        ss.insert(x + 1);
        ss.insert(y);
        break;
      }
    }
    if (not b) break;
    if (ssize(ss) >= 501) break;
    auto& V = P[ssize(ss)];
    for (ll x : ss) V.push_back(x);
  }

  ll T; cin >> T;
  REP(t, 0, T) {
    ll N; cin >> N;
    if (N == 1) {
      cout << "Yes\n1\n";
    }else if (N == 2) {
      cout << "No\n";
    }else {
      cout << "Yes\n";
      REPOUT(i, 0, N, P[N][i], " ");
    }
  }

  return 0;
}

