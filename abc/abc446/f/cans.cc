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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    if (u != v) {
      fwd[u].emplace_back(v);
    }
  }
  /*
  REP(i, 0, N) {
    ranges::sort(fwd[i]);
    auto it = unique(ALL(fwd[i]));
    fwd[i].erase(it, fwd[i].end());
  }
  */
  set<ll> skipped;
  set<ll> deleted;
  deleted.insert(0);

  REP(nd, 0, N) {
    if (not deleted.empty() and *deleted.begin() == nd) {
      deleted.erase(nd);
      vector<ll> vec;
      vec.push_back(nd);
      while (not vec.empty()) {
        ll x = vec.back(); vec.pop_back();
        for (ll peer : fwd[x]) {
          if (peer < nd) {
            auto it = skipped.find(peer);
            if (it != skipped.end()) {
              vec.push_back(peer);
              skipped.erase(it);
            }
          }else if (nd < peer) deleted.insert(peer);
        }
      }
    }else {
      skipped.insert(nd);
    }
    if (skipped.empty()) {
      cout << ssize(deleted) << "\n";
    }else {
      cout << -1 << "\n";
    }

  }

  return 0;
}

