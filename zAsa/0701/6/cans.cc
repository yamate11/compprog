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

  ll N; cin >> N;
  // @InpVec(2*N, A) [50GYeeNy]
  auto A = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [50GYeeNy]

  auto ord = sortedIndex(A);
  vector<ll> rev(2*N);
  REP(i, 0, 2*N) rev[ord[i]] = i;

  string ans;
  bool mode;
  ll ht = 0;
  REP(i, 0, 2*N) {
    if (ht == 0) {
      mode = rev[i] < N;
      ans += '(';
    }else if ((rev[i] < N) == mode) ans += '(';
    else                            ans += ')';
    ht += ans.back() == '(' ? 1 : -1;
  }
  cout << ans << endl;

  return 0;
}

