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

  string S; cin >> S;
  auto vec = rle(S);
  decltype(vec) V;
  if (vec[0].first == '<') V.emplace_back('>', 0);
  for (auto& x : vec) V.push_back(x);
  if (V.back().first == '>') V.emplace_back('<', 0);
  assert(ssize(V) % 2 == 0);
  ll r = 0;
  ll ans = 0;
  REP(i, 0, ssize(V) / 2) {
    auto [c1, n1] = V[2*i];
    auto [c2, n2] = V[2*i + 1];
    ll s1 = n1 * (n1 + 1) / 2;
    ll s2 = n2 * (n2 + 1) / 2;
    ans += s1 + s2;
    ans -= min(r, n1);
    r = n2;
  }
  cout << ans << endl;

  return 0;
}

