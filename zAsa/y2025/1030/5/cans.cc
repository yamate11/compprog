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

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto ask = [&]() -> vector<ll> {
    ll k; cin >> k;
    if (k == -1) throw myexc();
    vector<ll> ret(k);
    REP(i, 0, k) {
      ll a; cin >> a;
      ret[i] = a - 1;
    }
    return ret;
  };
  auto go = [&](ll c) -> void {
    cout << c + 1 << endl;
  };
  auto report = [&]() -> void {
    string x; cin >> x;
    throw myexc();
  };

  ll N, M; cin >> N >> M;
  vector<bool> visited(N);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    if (nd == N - 1) {
      report();
    }
    auto cs = ask();
    for (ll c : cs) {
      if (visited[c]) continue;
      visited[c] = true;
      go(c);
      rF(rF, c, nd);
    }
    go(pt);
    ask();
  };
  try {
    dfs(dfs, 0, -1);
  }catch(myexc& e) {
  }

  return 0;
}

