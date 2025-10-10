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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    string S; cin >> S;
    auto P = rle(S);

    auto f = [&](char c0) -> ll {
      if (ssize(P) == 1) return 0;
      ll j;
      ll cur;
      if (P[0].first == c0) {
        cur = 0;
        REP(i, 1, ssize(P)) {
          if (P[i].first == c0) cur += 2 * P[i].second;
          else                  cur += 1 * P[i].second;
        }
        j = 0;
      }else {
        cur = P[0].second;
        REP(i, 2, ssize(P)) {
          if (P[i].first == c0) cur += 2 * P[i].second;
          else                  cur += 1 * P[i].second;
        }
        j = 1;
      }
      ll ans = cur;
      for (; j + 2 < ssize(P); j += 2) {
        cur = cur + 2 * (P[j].second - P[j + 2].second);
        ans = min(ans, cur);
      }
      return ans;
    };

    ll a = f('0');
    ll b = f('1');
    return min(a, b);
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

