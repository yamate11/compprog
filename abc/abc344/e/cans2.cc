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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [lUsSh1XV]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [lUsSh1XV]

  vector<ll> vec{-1LL, -1LL};
  vector<ll> prv{-1LL, 0LL};
  vector<ll> nxt{1LL, -1LL};
  map<ll, ll> mp;

  auto my_insert = [&](ll p, ll x) -> ll {
    ll q = nxt[p];
    ll k = ssize(vec);
    vec.push_back(x);
    nxt.push_back(q);
    nxt[p] = k;
    prv.push_back(p);
    prv[q] = k;
    mp[x] = k;
    return k;
  };
  auto my_erase = [&](ll p) -> void {
    ll q = prv[p];
    ll r = nxt[p];
    nxt[q] = r;
    prv[r] = q;
    mp[vec[p]] = -1LL;
  };

  {
    ll p = 0;
    REP(i, 0, N) {
      p = my_insert(p, A[i]);
    }
  }
  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x, y; cin >> x >> y;
      ll p = mp[x];
      my_insert(p, y);
    }else if (tp == 2) {
      ll x; cin >> x;
      ll p = mp[x];
      my_erase(p);
    }else assert(0);
  }
  vector<ll> ans;
  {
    ll i = nxt[0];
    while (true) {
      if (vec[i] < 0) break;
      ans.push_back(vec[i]);
      i = nxt[i];
    }
  }
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}

