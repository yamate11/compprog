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
// published at https://github.com/yamate11/compprog-clib/blob/master/sortedIndex.cc

template<typename INT = long long int>
vector<INT> sortedIndexCFAI(const auto& vec, auto idx_comp) { // Comparison Function Arguments are Indices
  vector<INT> ret(vec.size());
  iota(ret.begin(), ret.end(), (INT)0);
  sort(ret.begin(), ret.end(), idx_comp);
  return ret;
}

template<typename INT = long long int, typename Collection, typename Comp = less<typename Collection::value_type>>
vector<INT> sortedIndex(const Collection& vec, Comp comp = Comp()) {
  return sortedIndexCFAI<INT>(vec, [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2CFAI(const auto& vec, auto idx_comp) {
  auto ord2idx = sortedIndexCFAI<INT>(vec, idx_comp);
  vector<INT> idx2ord(vec.size());
  for (size_t i = 0; i < vec.size(); i++) idx2ord[ord2idx[i]] = i;
  return {move(ord2idx), move(idx2ord)};
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2(const auto& vec, auto comp) {
  return sortedIndex2CFAI<INT>(vec, [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
}

template<typename INT = long long int, typename Collection>
pair<vector<INT>, vector<INT>> sortedIndex2(const Collection& vec) {
  return sortedIndex2<INT>(vec, less<typename Collection::value_type>());
}


// ---- end sortedIndex.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, S, type=string) [OAjXBKtS]
    auto S = vector(N, string());
    for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
    // @End [OAjXBKtS]
  };
  auto comp = [&](const string& s, const string& t) -> bool { return s + t < t + s; };
  auto ord = sortedIndex(S, comp);
  vector<ll> A(N + 1);
  REP(ii, 0, N) A[ii + 1] = A[ii] + ssize(S[ord[ii]]);
  ll pos = -1;
  char c0 = ' ';
  REP(ii, 0, N - 1) {
    ll i = ord[ii];
    ll j = ord[ii + 1];
    string s1 = A[i] + A[j];
    string s2 = A[j] + A[i];
    if (s1 == s2) {
      string ans;
      REP(jj, 0, N) ans += A[ord[jj]];
      cout << ans << endl;
      return 0;
    }else {
      REP(t, 0, ssize(s1)) {
        if (s1[t] != s2[t]) {
          if (pos < t
        }
      }
    }
    
    
  }


  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

