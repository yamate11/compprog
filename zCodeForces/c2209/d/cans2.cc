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
vector<INT> sortedIndex(const auto& vec, auto comp) {
  vector<INT> ret(vec.size());
  iota(ret.begin(), ret.end(), (INT)0);
  sort(ret.begin(), ret.end(), [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2(const auto& vec, auto comp) {
  auto ord2idx = sortedIndex(vec, comp);
  vector<INT> idx2ord(vec.size());
  for (size_t i = 0; i < vec.size(); i++) idx2ord[ord2idx[i]] = i;
  return {move(ord2idx), move(idx2ord)};
}

template<typename INT = long long int, typename Collection>
vector<INT> sortedIndex(const Collection& vec) {
  return sortedIndex<INT>(vec, less<typename Collection::value_type>());
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

  auto f = [&](auto& A, const string& chars) -> string {
    if (A[1] == 0) return string(1, chars[2]);
    ll z = A[2] - (A[0] + A[1]);
    if (z >= -1) {
      string s(z >= 1 ? 1 : 0, chars[2]);
      REP(i, 0, A[0]) {
        s += chars[0];
        s += chars[2];
      }
      REP(i, 0, A[1]) {
        s += chars[1];
        s += chars[2];
      }
      if (z == -1) s.pop_back();
      return s;
    }
    bool isodd = (A[0] + A[1] + A[2]) % 2 != 0;
    if (isodd) A[2]++;
    ll p = (A[0] + A[1] + A[2]) / 2;
    ll x0 = p - A[0];
    ll x1 = p - A[1];
    ll x2 = p - A[2];
    string s;
    REP(i, 0, x0) {
      s += chars[2];
      s += chars[1];
    }
    REP(i, 0, x2) {
      s += chars[0];
      s += chars[1];
    }
    REP(i, 0, x1) {
      s += chars[0];
      s += chars[2];
    }
    if (isodd) s.pop_back();
    return s;
  };

  auto solve = [&]() -> string {
    vector<ll> A(3);
    string s0 = "RGB";
    REP(i, 0, 3) cin >> A[i];
    auto ord = sortedIndex(A);
    ranges::sort(A);
    string s1 = string("") + s0[ord[0]] + s0[ord[1]] + s0[ord[2]];
    return f(A, s1);
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

