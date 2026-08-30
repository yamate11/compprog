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

// @DefStruct(sta, (a, b, c)) [O4uT9zNc]
struct sta {
  ll a{};
  ll b{};
  ll c{};
  string show() const {
    return "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")";
  }
  bool operator==(const sta&) const = default;
};
// @End [O4uT9zNc]

struct A {
  int x;
  // A() = default; // (*)
  // A(int x_ = 0) : x(x_) {}
};

int main() {
  sta s;
  cout << s.c << endl;

  // @InpNbrList(N, M, nbr, dec=1, read=W) [nKshv2RT]
  struct nbr_t {
    int nd{};
    ll W{};
    string show() const {
      return "(" + to_string(nd) + ", " + to_string(W) + ")";
    }
    bool operator==(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    nbr[u].emplace_back(v, W);
    nbr[v].emplace_back(u, W);
  }
  // @End [nKshv2RT]

  A a{};
  cout << a.x << endl;
  A b;
  cout << b.x << endl;
}

