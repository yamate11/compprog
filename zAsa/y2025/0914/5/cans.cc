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
  ll x, y; cin >> x >> y;
  vector vec(2, vector<ll>());
  vec[1].push_back(0);
  if (s[0] == 'T') vec[0].push_back(0);
  {
    ll idx = 0;
    for (auto [c, t] : rle(s)) {
      if (c == 'F') vec[idx].push_back(t);
      else if (t % 2 != 0) idx = 1 - idx;
    }
  }
  
  auto check = [&](ll idx, ll g) -> bool {
    ll K = ssize(s);
    vector tbl_init(2*K + 1, false);
    auto tbl = tbl_init;
    tbl[K] = true;
    bool first = true;
    for (ll p : vec[idx]) {
      auto prev = move(tbl);
      tbl = tbl_init;
      REP(q, 0, 2*K + 1) {
        if (prev[q]) {
          tbl[q + p] = true;
          if (not first) tbl[q - p] = true;
        }
      }
      if (first) first = false;
    }
    return tbl[K + g];
  };

  bool b1 = check(0, x);
  bool b2 = check(1, y);
  cout << (b1 and b2 ? "Yes\n" : "No\n");

  return 0;
}

