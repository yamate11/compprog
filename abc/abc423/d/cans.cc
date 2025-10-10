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

  ll N, K; cin >> N >> K;
  // @InpMVec(N, (A, B, C)) [AVaQuaXy]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [AVaQuaXy]

  vector<ll> ans(N);
  enum kind { OUT, IN };
  using ev_t = tuple<ll, kind, ll>;
  priority_queue<ev_t, vector<ev_t>, greater<ev_t>> ev;
  REP(i, 0, N) ev.emplace(A[i], IN, i);
  ll cap = K;
  queue<ll> waiting;
  while (not ev.empty()) {
    auto [t, kd, i] = ev.top(); ev.pop();
    if (kd == IN) {
      if (not waiting.empty()) {
        waiting.push(i);
      }else if (C[i] <= cap) {
        ans[i] = t;
        cap -= C[i];
        ev.emplace(t + B[i], OUT, i);
      }else {
        waiting.push(i);
      }
    }else if (kd == OUT) {
      cap += C[i];
      while (not waiting.empty()) {
        ll j = waiting.front();
        if (C[j] <= cap) {
          waiting.pop();
          ans[j] = t;
          cap -= C[j];
          ev.emplace(t + B[j], OUT, j);
        }else {
          break;
        }
      }
    }
  }
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

