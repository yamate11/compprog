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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main() {
  ll N; cin >> N;
  vector<ll> A(N);
  vector<ll> hist;
  ll base = 0;
  REP(i, 0, N) {
    ll a; cin >> a;
    A[i] = a;
    hist.push_back(i);
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      base = x;
      while (not hist.empty()) {
        ll i = hist.back(); hist.pop_back();
        A[i] = 0;
      }
    }else if (tp == 2) {
      ll i, x; cin >> i >> x; i--;
      A[i] += x;
      hist.push_back(i);
    }else if (tp == 3) {
      ll i; cin >> i; i--;
      cout << base + A[i] << endl;
    }
  }

  return 0;
}

