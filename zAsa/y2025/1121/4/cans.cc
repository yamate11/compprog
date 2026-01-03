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

  string s; cin >> s;
  auto v = rle(s);
  ll idx = 0;
  vector<ll> w;
  while (true) {
    if (idx == ssize(v) or v[idx].first != 'x') w.push_back(0);
    else {
      w.push_back(v[idx].second);
      idx++;
    }
    if (idx == ssize(v)) break;
    auto [c, n] = v[idx];
    REP(i, 0, n - 1) {
      w.push_back(c - 'a');
      w.push_back(0);
    }
    w.push_back(c - 'a');
    idx++;
  }
  ll i = 0;
  ll j = ssize(w) - 1;
  ll ans = 0;
  while (i < j) {
    ans += abs(w[i] - w[j]);
    i++; j--;
    if (i >= j) break;
    if (w[i] != w[j]) {
      cout << -1 << endl;
      return 0;
    }
    i++; j--;
  }
  cout << ans << endl;
  return 0;
}

