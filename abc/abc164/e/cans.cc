#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, S; cin >> N >> M >> S;
  using Tuple = tuple<ll, ll, ll>;
  vector nbr(N, vector<Tuple>());
  vector<ll> A(M);
  for (ll i = 0; i < M; i++) {
    ll u, v, a, b; cin >> u >> v >> a >> b; u--; v--;
    nbr.at(u).emplace_back(v, a, b);
    nbr.at(v).emplace_back(u, a, b);
    A.at(i) = a;
  }
  sort(A.begin(), A.end(), greater<>());
  ll lim = 1;
  for (ll i = 0; i < N-1; i++) lim += A.at(i);
  vector<ll> C(N), D(N);
  for (ll i = 0; i < N; i++) {
    ll c, d; cin >> c >> d;
    C.at(i) = c;
    D.at(i) = d;
  }
  vector rec(N, vector(lim, LLONG_MAX));
  priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pque;
  if (S >= lim) S = lim - 1;
  ll cnt = 1;
  auto check = [&](ll t, ll n, ll s) -> void {
    if (!(0 <= s && s < lim && t < rec.at(n).at(s))) return;
    pque.emplace(t, n, s);
    if (rec.at(n).at(0) == LLONG_MAX) cnt++;
    for (ll y = s; y >= 0 && t < rec.at(n).at(y); y--) rec.at(n).at(y) = t;
  };
  rec.at(0).at(S) = 0;
  pque.emplace(0, 0, S);
  ll curT = 0;
  ll cIdx = 1;
  auto done = [&]() -> bool {
    while (cIdx < N && rec.at(cIdx).at(0) <= curT) cIdx++;
    return cIdx == N;
  };
  while (!done()) {
    auto [t, i, s] = pque.top(); pque.pop();
    curT = t;
    if (rec.at(i).at(s) < t) continue;
    check(t + D.at(i), i, s + C.at(i));
    for (auto [j, a, b] : nbr.at(i)) {
      check(t + b, j, s - a);
    }
  }
  for (ll j = 1; j < N; j++) {
    cout << rec.at(j).at(0) << "\n";
  }

  return 0;
}

