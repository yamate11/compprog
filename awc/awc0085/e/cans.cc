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

// @@ !! LIM(f:intDiv)

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpMVec(2*N, ((B, dec=1), A)) [zFKif51A]
  auto B = vector(2*N, ll());
  auto A = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) {
    ll v1; cin >> v1; v1 -= 1; B[i] = v1;
    ll v2; cin >> v2; A[i] = v2;
  }
  // @End [zFKif51A]

  ll tot = accumulate(ALL(A), 0LL);
  if (tot < K) {
    cout << -1 << endl;
    return 0;
  }

  vector C(2*N, 0LL);
  REP(i, 0, 2*N) C[B[i]]++;
  ll i0 = ranges::max_element(C) - C.begin();
  ll cmax = C[i0];
  if (cmax <= N) {
    cout << 1 << endl;
    return 0;
  }
  ll num_other = 2*N - cmax;

  vector<ll> other;
  vector<ll> tgen;
  REP(i, 0, 2*N) {
    if (B[i] == i0) tgen.push_back(A[i]);
    else other.push_back(A[i]);
  }
  ll sum1 = accumulate(ALL(other), 0LL);
  ranges::sort(tgen, greater<ll>());
  ll a = 0;
  while (true) {
    if (sum1 >= K) break;
    sum1 += tgen[a];
    a++;
  }
  if (num_other == 0) {
    cout << a << endl;
  }else {
    cout << divCeil(a, num_other + 1) << endl;
  }

  return 0;
}

