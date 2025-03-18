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
  auto enc = rle(S);
  ll ans = 0;
  ll i0;
  if (enc[0].first == '>') {
    ll m = enc[0].second;
    ans = m * (m + 1) / 2;
    i0 = 1;
  }else {
    ans = 0;
    i0 = 0;
  }
  for (ll i = i0; i + 1 < ssize(enc); i += 2) {
    ll ma = enc[i].second;
    ll mb = enc[i + 1].second;
    ll mx = min(ma, mb);
    ll my = max(ma, mb);
    ans += my * (my + 1) / 2 + (mx - 1) * mx / 2;
  }
  auto [c, m] = enc.back();
  if (c == '<') {
    ans += m * (m + 1) / 2;
  }
  cout << ans << endl;

  return 0;
}

