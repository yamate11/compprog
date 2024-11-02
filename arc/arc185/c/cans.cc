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

constexpr ll bssz = (ll)1e6 + 10;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto aout = [&](ll x, ll y, ll z) -> void {
    vector<ll> vec{x, y, z};
    sort(ALL(vec));
    REPOUT(i, 0, 3, vec[i] + 1, " ");
  };

  ll N, X; cin >> N >> X;
  // @InpVec(N, A) [YRp8ETWp]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [YRp8ETWp]

  vector<vector<ll>> dup(bssz);
  REP(i, 0, N) dup[A[i]].push_back(i);
  if (X % 3 == 0) {
    auto& vv = dup[X / 3];
    if (ssize(vv) >= 3) {
      aout(vv[0], vv[1], vv[2]);
      return 0;
    }
  }
  REP(x, 0, X) {
    if (ssize(dup[x]) >= 2) {
      ll y = X - 2 * x;
      if (y >= 0 and not dup[y].empty()) {
        aout(dup[x][0], dup[x][1], dup[y][0]);
        return 0;
      }
    }
  }
  bitset<bssz> bs;
  REP(i, 0, N) bs.set(A[i]);
  bitset<bssz> bs_un;
  bitset<bssz> bs_in;
  auto cur = bs;
  REP(x, 0, X) if (bs[x]) {
    cur.set(x, false);
    auto cur_shift = cur << x;
    bs_in |= bs_un & cur_shift;
    bs_un |= cur_shift;
  }
  REP(x, 0, X) {
    if (bs[x]) {
      ll y = X - x;
      if (bs_un[y]) {
        if (bs_in[y]) {
          REP(a, 0, X) {
            ll b = y - a;
            if (a != x and b != x and bs[a] and bs[b]) {
              aout(dup[x][0], dup[a][0], dup[b][0]);
              return 0;
            }
          }
          assert(0);
        }else {
          if (not (y >= x and bs[y - x])) {
            REP(a, 0, X) {
              ll b = y - a;
              if (a != x and b != x and bs[a] and bs[b]) {
                aout(dup[x][0], dup[a][0], dup[b][0]);
                return 0;
              }
            }
            assert(0);
          }
        }
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

