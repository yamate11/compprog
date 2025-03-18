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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpMVec(N, (A, (B, dec=1))) [eyO9whkD]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [eyO9whkD]
  ll numSch = 2e5;
  vector rates(numSch, multiset<ll>());
  multiset<ll> maxes;
  REP(i, 0, N) rates[B[i]].insert(A[i]);
  REP(i, 0, numSch) {
    if (not rates[i].empty()) {
      maxes.insert(*prev(rates[i].end()));
    }
  }
  REP(_q, 0, Q) {
    ll c, d; cin >> c >> d; c--; d--;
    ll p = B[c];
    B[c] = d;
    auto it = maxes.find(*prev(rates[p].end()));
    maxes.erase(it);
    if (not rates[d].empty()) {
      it = maxes.find(*prev(rates[d].end()));
      maxes.erase(it);
    }
    auto it1 = rates[p].find(A[c]);
    rates[p].erase(it1);
    rates[d].insert(A[c]);
    if (not rates[p].empty()) {
      maxes.insert(*prev(rates[p].end()));
    }
    maxes.insert(*prev(rates[d].end()));
    cout << *maxes.begin() << "\n";
  }

  return 0;
}

