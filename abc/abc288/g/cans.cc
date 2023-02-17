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
  vector<ll> P3(N + 1);
  P3[0] = 1;
  REP(i, 1, N + 1) P3[i] = 3 * P3[i - 1];
  vector<ll> A(P3[N]);
  REP(i, 0, P3[N]) cin >> A[i];
  using vll = vector<ll>;
  auto f = [&](auto rF, ll st, ll pidx) -> vll {
    if (pidx == 1) {
      ll a = A[st]; ll b = A[st + 1]; ll c = A[st + 2];
      return vll{b - c, a + c - b, b - a};
    }else {
      vector<vll> z;
      REP(i, 0, 3) z.push_back(rF(rF, st + i * P3[pidx - 1], pidx - 1));
      vll ret(P3[pidx]);
      REP(i, 0, P3[pidx - 1]) {
        ll a = z[0][i]; ll b = z[1][i]; ll c = z[2][i];
        ret[i] = b - c;
        ret[i + P3[pidx - 1]] = a + c - b;
        ret[i + 2 * P3[pidx - 1]] = b - a;
      }
      return ret;
    }
  };
  auto ans = f(f, 0, N);
  REPOUT(i, 0, SIZE(ans), ans[i], " ");

  return 0;
}

