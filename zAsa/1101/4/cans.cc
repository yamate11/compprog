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

// @@ !! LIM(rle)

// ---- inserted library file rle.cc

template<class InputIt, class OutputIt>
OutputIt rle_iter(InputIt first, InputIt last, OutputIt d_first) {
  InputIt itA = first;
  OutputIt oit = d_first;
  while (itA != last) {
    InputIt itB = next(itA);
    for (; itB != last and *itA == *itB; itB++);
    *oit = make_pair(*itA, itB - itA);
    itA = itB;
    oit++;
  }
  return oit;
}

template<class V>
auto rle(V vec) {
  vector<pair<typename V::value_type, ll>> ret;
  rle_iter(vec.begin(), vec.end(), back_inserter(ret));
  return ret;
}

// ---- end rle.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  auto tmp = rle(S);
  decltype(tmp) vec;
  if (tmp[0].first == '0') vec.emplace_back('1', 0);
  for (auto v : tmp) vec.push_back(v);
  if (tmp.back().first == '0') vec.emplace_back('1', 0);
  ll sz = ssize(vec);
  assert(sz % 2 != 0);
  if (sz <= 2 * K + 1) {
    cout << N << endl;
    return 0;
  }
  ll cur = 0;
  REP(i, 0, 2*K + 1) cur += vec[i].second;
  ll ans = cur;
  REP(i, 0, (sz - (2 * K + 1)) / 2) {
    cur +=  - vec[2*i].second - vec[2*i + 1].second + vec[2*K + 1 + 2*i].second + vec[2*K + 1 + 2*i + 1].second;
    ans = max(ans, cur);
  }
  cout << ans << endl;
  

  return 0;
}

