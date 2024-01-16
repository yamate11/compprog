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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [WuCtkGtk]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [WuCtkGtk]
  vector<ll> pos;
  vector<ll> neg;
  ll M = 0;
  vector<pll> hist;
  REP(i, 0, N) {
    if (A[i] >= 0) pos.push_back(A[i]);
    else neg.push_back(A[i]);
  }
  if (SIZE(pos) > 0 and SIZE(neg) > 0) {
    ll cur1 = pos[0];
    ll cur2 = neg[0];
    REP(i, 1, SIZE(neg)) {
      hist.emplace_back(cur1, neg[i]);
      cur1 -= neg[i];
    }
    REP(i, 1, SIZE(pos)) {
      hist.emplace_back(cur2, pos[i]);
      cur2 -= pos[i];
    }
    hist.emplace_back(cur1, cur2);
    M = cur1 - cur2;
  }else if (SIZE(pos) == 0) {
    ll i0 = max_element(ALL(neg)) - neg.begin();
    ll cur = neg[i0];
    ll pres = 0;
    bool pdone = false;
    REP(i, 0, N) {
      if (i == i0) continue;
      if (not pdone) {
        pdone = true;
        pres = neg[i];
      }else {
        hist.emplace_back(cur, neg[i]);
        cur -= neg[i];
      }
    }
    hist.emplace_back(cur, pres);
    M = cur - pres;
  }else if (SIZE(neg) == 0) {
    ll i0 = min_element(ALL(pos)) - pos.begin();
    ll cur = pos[i0];
    ll pres = 0;
    bool pdone = false;
    REP(i, 0, N) {
      if (i == i0) continue;
      if (not pdone) {
        pdone = true;
        pres = pos[i];
      }else {
        hist.emplace_back(cur, pos[i]);
        cur -= pos[i];
      }
    }
    hist.emplace_back(pres, cur);
    M = pres - cur;
  }
  cout << M << "\n";
  for (auto [x, y] : hist) {
    cout << x << " " << y << "\n";
  }

  return 0;
}

