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

  ll N, M; cin >> N >> M;
  using ev_t = tuple<ll, ll, ll, ll>;
  vector<ev_t> event;
  const ll START = 1;
  const ll END = 0;
  for (ll i = 0; i < M; i++) {
    ll l, r, x; cin >> l >> r >> x; l--;
    event.emplace_back(l, START, i, r - l - x);
    event.emplace_back(r, END, i, -1);
  }
  sort(event.begin(), event.end());
  event.emplace_back(1e9, -1, -1, -1);

  vector<ll> ans(N);
  using sta = pair<ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  ll evi = 0;
  ll step = 0;
  vector<bool> finished(M);
  for (ll i = 0; i < N; i++) {
    for (;; evi++) {
      auto [t, type, j, y] = event[evi];
      if (i != t) break;
      if (type == END) {
        finished[j] = true;
      }else if (type == START) {
        pque.emplace(step + y, j);
      }
    }
    ll st = -1;
    while (! pque.empty()) {
      auto [s, j] = pque.top();
      if (!finished[j]) {
        st = s;
        break;
      }
      pque.pop();
    }
    if (step == st) {
      ans[i] = 1;
    }else {
      ans[i] = 0;
      step++;
    }
  }
  for (ll x : ans) cout << x << " ";
  cout << endl;

  return 0;
}

