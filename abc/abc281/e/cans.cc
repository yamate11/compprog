#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

template<typename C>
struct myset {
  multiset<ll, C> ss;
  ll val;
  myset() : ss(), val(0) {}
  void add(ll x) {
    ss.insert(x);
    val += x;
  }
  bool del(ll x) {
    auto it = ss.find(x);
    if (it == ss.end()) return false;
    ss.erase(it);
    val -= x;
    return true;
  }
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, A) [24PS4Qep]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [24PS4Qep]
  myset<greater<ll>> ssmall;
  myset<less<ll>> sbig;
  vector<ll> ans;
  REP(i, 0, N) {
    if (i >= M) if (not sbig.del(A[i - M])) ssmall.del(A[i - M]);
    if (SIZE(ssmall.ss) >= K) sbig.add(A[i]);
    else                      ssmall.add(A[i]);
    if (not ssmall.ss.empty() and not sbig.ss.empty()) {
      ll vs = *(ssmall.ss.begin());
      ll vb = *(sbig.ss.begin());
      if (vs > vb) {
        ssmall.del(vs);
        sbig.del(vb);
        ssmall.add(vb);
        sbig.add(vs);
      }
    }
    if (i >= M - 1) ans.push_back(ssmall.val);
  }
  REPOUT(i, 0, SIZE(ans), ans[i], " ");


  return 0;
}

