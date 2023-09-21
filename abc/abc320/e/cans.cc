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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, (T, W, S)) [wOXuS245]
  auto T = vector(M, ll());
  auto W = vector(M, ll());
  auto S = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; W[i] = v2;
    ll v3; cin >> v3; S[i] = v3;
  }
  // @End [wOXuS245]
  
  struct ev {
    ll t;
    ev(ll t_) : t(t_) {}
  };
  struct ev_man : ev {
    ll i;
    ev_man(ll t_, ll i) : ev(t_), i_(i) {}
  };
  struct ev_somen : ev {
    ll w;
    ll s;
    ev_somen(ll t_, ll w_, ll s_) : ev(t_), w(w_), s(s_) {}
  };

  priority_queue<ev, vector<ev>, greater<ev>> pque;
  auto ans = vector(N, 0LL);
  set<ll> ss;
  REP(i, 0, N) ss.insert(i);
  REP(i, 0, M) pque.push(ev_somen(T[i], W[i], S[i]));
  while (not pque.empty()) {
    auto obj = pque.top(); pque.pop();

    if (kd == MAN) {
      ss.insert(x);
    }else if (kd == SOMEN) {
      if (not ss.empty()) {
        auto it = ss.begin();
        ll p = *it;
        ss.erase(it);
        ans[p] += x;
        pque.emplace(t + y, MAN, p, -1);
      }
    }else assert(0);

  }
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

