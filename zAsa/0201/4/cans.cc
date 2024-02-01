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

  ll W, H; cin >> W >> H;
  ll N; cin >> N;
  // @InpMVec(N, (P, Q)) [kMa5LkNk]
  auto P = vector(N, ll());
  auto Q = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; Q[i] = v2;
  }
  // @End [kMa5LkNk]
  ll A; cin >> A;
  vector<ll> vecA{0};
  REP(i, 0, A) {
    ll a; cin >> a;
    vecA.push_back(a);
  }
  vecA.push_back(W);
  ll B; cin >> B;
  vector<ll> vecB{0};
  REP(i, 0, B) {
    ll b; cin >> b;
    vecB.push_back(b);
  }
  vecB.push_back(H);

  map<pll, ll> mp;
  REP(i, 0, N) {
    ll p = lower_bound(ALL(vecA), P[i]) - vecA.begin() - 1;
    ll q = lower_bound(ALL(vecB), Q[i]) - vecB.begin() - 1;
    mp[pll(p, q)] ++;
  }
  ll vmax = 0;
  ll vmin = N;
  ll cnt = 0;
  for (auto [p, v] : mp) {
    vmax = max(vmax, v);
    vmin = min(vmin, v);
    cnt++;
  }
  if (cnt < (A + 1) * (B + 1)) vmin = 0;
  cout << vmin << " " << vmax << endl;


  return 0;
}

