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

  ll N; cin >> N;
  // @InpVec(N, A) [UbKZVqMH]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [UbKZVqMH]

  ll s = 0;

  auto func1 = [&]() -> void {
    ll t = 0;
    REP(i, 0, N) t += A[i] * (i * s);
    ll delta = 0;
    if (t >= 0) {
      delta = - divFloor(t, s);
    } else {
      delta = divCeil(-t, s);
    }
    t += delta * s;
    vector<ll> ans(N);
    ans[0] = delta - t;
    REP(i, 0, N) ans[i] = i * s + delta;
    cout << "Yes\n";
    REPOUT(i, 0, N, ans[i], " ");
  };

  REP(i, 0, N) s += A[i];
  if (s < 0) {
    REP(i, 0, N) A[i] = - A[i];
    s = -s;
    func1();
    return 0;
  }else if (s > 0) {
    func1();
    return 0;
  }
  if (A[0] == -1) REP(i, 0, N) A[i] = -A[i];
  ll cum = 0;
  ll p = -1;
  REP(i, 0, N) {
    cum += A[i];
    if (cum < 0) {
      p = i;
      break;
    }
  }
  if (p == -1) {
    cout << "No\n";
    return 0;
  }
  ll q = -1;
  cum = 0;
  REPrev(i, N-1, 0) {
    cum -= A[i];
    if (cum < 0) {
      q = i;
      break;
    }
  }
  ll alpha = 0, beta = 0, gamma = 0;
  REP(i, 0, p) beta += A[i] * i;
  REP(i, p + 1, q) gamma += A[i] * i;
  REP(i, q + 1, N) alpha += A[i] * i;
  ll M = N;
  if ((alpha + beta) * M + gamma >= -N ) {
    M = divCeil(gamma + N, -(alpha + beta));
  }
  ll Z = - (alpha + beta) * M - gamma;
  vector<ll> ans(N);
  REP(i, 0, p) ans[i] = M * -(p - i);
  ans[p] = 0;
  REP(i, p, q) ans[i] = i - p;
  ans[q] = Z;
  REP(i, q + 1, N) ans[i] = Z + M * (i - q);
  cout << "Yes\n";
  REPOUT(i, 0, N, ans[i], " ");


  return 0;
}

