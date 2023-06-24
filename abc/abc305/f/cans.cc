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

struct myexc : exception {};

vector<ll> rcv() {
  ll K; cin >> K;
  vector ret(K, 0LL);
  REP(i, 0, K) {
    ll x; cin >> x; x--;
    ret[i] = x;
  }
  return ret;
}

void rcv_fin() {
  string s; cin >> s;
  return;
}

void move(ll nd) {
  cout << nd + 1 << endl;
}

vector<ll> get_nlist(auto& vec, ll pt) {
  vector<ll> ret;
  for (ll nd : vec) {
    if (nd == pt) continue;
    ret.push_back(nd);
  }
  return ret;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<bool> visited(N, false);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    auto vec = rcv();
    auto nlist = get_nlist(vec, pt);
    for (ll cld : nlist) {
      if (not visited[cld]) {
        visited[cld] = true;
        move(cld);
        if (cld == N - 1) {
          rcv_fin();
          throw myexc();
        }
        rF(rF, cld, nd);
        move(nd);
        auto dummy = rcv();
      }
    }
  };

  try {
    visited[0] = true;
    dfs(dfs, 0, -1);
  }catch (myexc& e) {
  }

  return 0;
}

