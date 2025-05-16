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

ll EXPR = 0;
ll TERM = 1;
ll FACTOR = 2;
ll NUMBER = 3;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector tbl(4, vector(N + 1, string()));
  
  using sta = pair<ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;

  auto update = [&](ll TP, ll val, string e) -> void {
    if (val <= N and (tbl[TP][val] == "" or ssize(tbl[TP][val]) > ssize(e))) {
      tbl[TP][val] = e;
      pque.emplace(val, TP);
    }
  };

  tbl[NUMBER][1] = "1";
  pque.emplace(1, NUMBER);
  while (not pque.empty()) {
    auto [val, kd] = pque.top(); pque.pop();
    const string& e = tbl[kd][val];
    if (kd == NUMBER) {
      update(NUMBER, val * 10 + 1, "1" + e);
      update(FACTOR, val, e);
    }else if (kd == FACTOR) {
      update(TERM, val, e);
      REP(i, 1, N + 1) if (tbl[TERM][i] != "") {
        update(TERM, val * i, tbl[TERM][i] + "*" + e);
      }
    }else if (kd == TERM) {
      update(EXPR, val, e);
      REP(i, 1, N + 1) if (tbl[EXPR][i] != "") {
        update(EXPR, val + i, tbl[EXPR][i] + "+" + e);
      }
      REP(i, 1, N + 1) if (tbl[FACTOR][i] != "") {
        update(TERM, val * i, e + "*" + tbl[FACTOR][i]);
      }
    }else if (kd == EXPR) {
      update(FACTOR, val, "(" + e + ")");
      REP(i, 1, N + 1) if (tbl[TERM][i] != "") {
        update(EXPR, val + i, e + "+" + tbl[TERM][i]);
      }
    }
  }
  string ans = "";
  REP(tp, 0, 4) {
    if (tbl[tp][N] != "" and (ans == "" or ssize(tbl[tp][N]) < ssize(ans))) ans = tbl[tp][N];
  }
  cout << ans << "\n";

  return 0;
}

