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
  // @InpNbrList(N, N, nbr, dec=1) [njkGBnX0]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [njkGBnX0]
  vector<ll> st;
  vector<bool> onst(N);
  auto dfs1 = [&](auto rF, ll nd, ll pt) -> ll {
    if (onst[nd]) return nd;
    onst[nd] = true;
    st.push_back(nd);
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      ll x = rF(rF, cld, nd);
      if (x >= 0) return x;
    }
    st.pop_back();
    onst[nd] = false;
    return -1;
  };
  ll nd = dfs1(dfs1, 0, -1);
  assert(nd >= 0);
  vector<ll> loop;
  bool eff = false;
  vector<ll> clsfy(N, -1);
  for (ll n : st) {
    if (n == nd) eff = true;
    if (eff) {
      loop.push_back(n);
    }
  }
  ll szl = SIZE(loop);
  REP(seq, 0, szl) {
    auto dfs2 = [&](auto rF, ll nd2, ll pt) -> void {
      clsfy[nd2] = seq;
      for (ll cld : nbr[nd2]) {
        if (cld == pt) continue;
        rF(rF, cld, nd2);
      }
    };
    ll root = loop[seq];
    ll exc1 = loop[imod(seq + 1, szl)];
    ll exc2 = loop[imod(seq - 1, szl)];
    clsfy[root] = seq;
    for (ll n : nbr[root]) {
      if (n != exc1 and n != exc2) dfs2(dfs2, n, root);
    }
  }
  
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll x, y; cin >> x >> y; x--; y--;
    cout << (clsfy[x] == clsfy[y] ? "Yes" : "No") << "\n";
  }

  return 0;
}

