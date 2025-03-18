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
  auto enc = rle(S);
  ll cnt = 0;
  ll idx = -1;
  REP(i, 0, ssize(enc)) {
    auto [c, n] = enc[i];
    if (c == '1') {
      cnt++;
      if (cnt == K) {
        idx = i;
        break;
      }
    }
  }
  string ans;
  REP(i, 0, ssize(enc)) {
    if (i == idx - 1) {
      REP(j, 0, enc[idx].second) ans += '1';
    }else if (i == idx) {
      REP(j, 0, enc[idx - 1].second) ans += '0';
    }else {
      REP(j, 0, enc[i].second) ans += enc[i].first;
    }
  }
  cout << ans << endl;

  return 0;
}

