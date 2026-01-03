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

// @@ !! LIM(sortedIndex)

// ---- inserted library file sortedIndex.cc

vector<int> sortedIndex(const auto& vec, auto comp) {
  vector<int> ret(vec.size());
  iota(ret.begin(), ret.end(), 0);
  sort(ret.begin(), ret.end(), [&vec, &comp](int i, int j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename Collection>
vector<int> sortedIndex(const Collection& vec) { return sortedIndex(vec, less<typename Collection::value_type>()); }

// ---- end sortedIndex.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpVec(N, A) [EJ4betGm]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [EJ4betGm]
    
    auto ord = sortedIndex(A);

    vector<pll> ans;
    if (M > N / 2) {
      cout << -1 << "\n";
      return;
    }
    else if (M > 0) {
      ll r = N - 2 * (M - 1);
      REP(i, 0, r - 1) ans.emplace_back(ord[i + 1], ord[i]);
      REP(j, 0, M - 1) ans.emplace_back(ord[r + 2*j + 1], ord[r + 2*j + 0]);
    }
    else if (M == 0) {
      ll s = 0;
      ll i0 = N - 2;
      for ( ; i0 >= 0; i0--) {
        s += A[ord[i0]];
        if (s >= A[ord[N - 1]]) break;
      }
      if (s < A[ord[N - 1]]) {
        cout << -1 << "\n";
        return;
      }
      REP(i, 0, i0) ans.emplace_back(ord[i], ord[i + 1]);
      REP(i, i0 + 1, N - 1) ans.emplace_back(ord[i], ord[N - 1]);
      ans.emplace_back(ord[i0], ord[N - 1]);
    }
    else assert(0);

    cout << ssize(ans) << "\n";
    for (auto [i, j] : ans) {
      cout << i + 1 << " " << j + 1 << "\n";
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

