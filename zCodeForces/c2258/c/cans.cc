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

  auto solve = [&]() -> void {
    auto ask = [&](ll d, ll i, ll j) -> bool {
      cout << "? " << i + 1 << " " << j + 1 << " " << d << endl;
      ll r; cin >> r;
      if (r == -1) assert(0);
      return r == 1;
    };
    auto report = [&](ll d, ll i, ll j) -> void {
      cout << "! " << i + 1 << " " << j + 1 << " " << d << endl;
    };

    ll N; cin >> N;
    if (N == 2) {
      report(1, 0, 1);
      return;
    }


    auto fst = [&]() -> pll {
      queue<ll> que;
      REP(i, 1, N) que.push(i);
      ll d = 2;
      while (ssize(que) >= 2) {
        ll a = que.front(); que.pop();
        if (ask(d, 0, a)) {
          que.push(a);
          d++;
        }
      }
      ll a = que.front();
      return pll(a, d - 1);
    };
    auto snd = [&](ll a0, ll d0) -> pll {
      queue<ll> que;
      REP(i, 1, N) if (i != a0) que.push(i);
      que.push(0);
      ll d = d0 + 1;
      while (ssize(que) >= 2) {
        ll a = que.front(); que.pop();
        if (ask(d, a0, a)) {
          que.push(a);
          d++;
        }
      }
      ll a = que.front();
      while (true) {
        bool b = ask(d, a0, a);
        if (not b) return pll(a, d - 1);
        d++;
      }
    };
    auto [a, d0] = fst();
    auto [b, d1] = snd(a, d0);
    report(d1, a, b);
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

