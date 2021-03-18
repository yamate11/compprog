#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  vector<ll> W(N), V(N);
  using stb = tuple<ll, ll, ll>;
  vector<stb> wvi;
  for (ll i = 0; i < N; i++) {
    ll w, v; cin >> w >> v;
    W[i] = w;
    V[i] = v;
    wvi.emplace_back(w, v, i);
  }
  vector<ll> X(M);
  using sta = pair<ll, ll>;
  vector<sta> Y;
  for (ll i = 0; i < M; i++) {
    ll x; cin >> x;
    X[i] = x;
    Y.emplace_back(x, i);
  }
  sort(Y.begin(), Y.end());
  sort(wvi.begin(), wvi.end());
  for (ll q = 0; q < Q; q++) {
    ll L, R; cin >> L >> R; L--;
    using stc = pair<ll, ll>;
    priority_queue<stc> pque;
    ll p = 0;
    ll tot = 0;
    for (ll i = 0; i < M; i++) {
      auto [x, ibox] = Y[i];
      if (L <= ibox && ibox < R) continue;
      while (p < N) {
        auto [w, v, ipack] = wvi[p];
        if (w > x) break;
        p++;
        pque.emplace(v, ipack);
      }
      if (pque.empty()) continue;
      auto [v, ipack] = pque.top(); pque.pop();
      tot += v;
    }
    cout << tot << "\n";
  }

  

  return 0;
}

