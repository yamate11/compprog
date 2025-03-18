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

  ll N; cin >> N;
  // @InpVec(N, A) [VCxS8TnO]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [VCxS8TnO]

  ll ans2 = 0;
  auto enc = rle(A);
  ll M = ssize(enc);
  ll i = 0;
  while (i < M) {
    while (i < M and enc[i].second == 1) i++;
    if (i == M) break;
    if (i + 1 == M or enc[i + 1].second == 1) {
      ans2 = max(ans2, 1LL);
      i++;
    }else {
      ll j = i + 1;
      while (j < M and enc[j].second == 2) j++;
      if (j == M) {
      }else if (enc[j].second == 1) {
      }else {
        j++;
      }
      set<ll> xs;
      ll k = i;
      ll m = i + 1;
      xs.insert(enc[k].first);
      while (m < j) {
        while (m < j and not xs.contains(enc[m].first)) {
          xs.insert(enc[m].first);
          m++;
        }
        ans2 = max(ans2, m - k);
        if (m == j) break;
        while (enc[k].first != enc[m].first) {
          xs.erase(enc[k].first);
          k++;
        }
        k++;
        m++;
      }
      if (j == M or enc[j].second == 1) i = j;
      else i = j - 1;
    }
  }
  cout << ans2 * 2 << endl;

  return 0;
}

