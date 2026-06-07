#include <bits/stdc++.h>
#include <cassert>
#include <boost/unordered/unordered_flat_map.hpp>
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

const ll primeB = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, seed, M, F; cin >> N >> seed >> M >> F;
  vector<ll> Q(M - 1);
  REP(i, 0, M - 1) { cin >> Q[i]; Q[i]--; }
  vector<ll> D(N);
  REP(i, 0, M) { cin >> D[i]; D[i]--; }

  vector<ll> parent(N);
  vector children(N, vector<ll>());
  vector<ll> C(N);
  ll state = seed;
  REP(i, 0, N - 1) {
    ll p; 
    if (i + 2 <= M) p = Q[i];
    else {
      p = state % (i + 1);
      state = (state * 1103515245 + 12345) % (1LL << 31);
    }
    parent[i + 1] = p;
    children[p].push_back(i + 1);
  }
  REP(i, 0, N) {
    if (i + 1 <= M) C[i] = D[i];
    else {
      C[i] = (state % F);
      state = (state * 1103515245 + 12345) % (1LL << 31);
    }
  }
  
  vector<ll> subtree_size(N);
  auto calc_subtree_size = [&](auto rF, ll nd) -> void {
    subtree_size[nd] = 1;
    for (ll c : children[nd]) {
      rF(rF, c);
      subtree_size[nd] += subtree_size[c];
    }
  };
  calc_subtree_size(calc_subtree_size, 0);

  // make the first child heaviest
  auto comp = [&](ll i, ll j) -> bool { return  subtree_size[i] > subtree_size[j]; };
  REP(nd, 0, N) if (ssize(children[nd]) >= 2) {
    ll i0 = ranges::max_element(children[nd], comp) - children[nd].begin();
    if (i0 > 0) swap(children[nd][0], children[nd][i0]);
  }
  
  vector<ll> ans_m(N);
  vector<ll> ans_k(N);
  using mymap = boost::unordered_flat_map<ll, ll>;

  auto main_dfs = [&](auto rF, ll nd) -> mymap {
    if (ssize(children[nd]) == 0) {
      mymap mp;
      mp[C[nd]] = 1;
      ans_m[nd] = 1;
      ans_k[nd] = 1;
      return mp;
    }else {
      ll heavy_child = children[nd][0];
      auto mp = rF(rF, heavy_child);
      ll m = ans_m[heavy_child];
      ll k = ans_k[heavy_child];
      /*
      ans_m[nd] = ans_m[heavy_child];
      ans_k[nd] = ans_k[heavy_child];
      */
      auto append = [&](ll col, ll num) -> void { // Adds (col, num) to the map and updates the answers.
        auto [it, b] = mp.try_emplace(col, num);
        if (not b) { // col has existed in mp.
          it->second += num;
        }
        if (m < it->second) {
          m = it->second;
          k = 1;
        }else if (m == it->second) {
          k++;
        }
      };
      // Appends the results of light children.
      REP(i, 1, ssize(children[nd])) {
        auto mpc = rF(rF, children[nd][i]);
        for (const auto& [col, num] : mpc) append(col, num);
      }
      // Appends the node itself.
      append(C[nd], 1);
      ans_m[nd] = m;
      ans_k[nd] = k;
      return mp;
    }
  };
  main_dfs(main_dfs, 0);

  ll ans = 0;
  REP(i, 0, N) ans = (ans + (ans_m[i] ^ (i + 1)) * (ans_k[i] ^ (i + 1))) % primeB;
  cout << ans << endl;
  return 0;
}

