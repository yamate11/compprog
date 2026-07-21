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

  ll Q, L; cin >> Q >> L;
  ll size = 0;
  vector<pll> stack;
  REP(_q, 0, Q) {
    string op; cin >> op;
    if (op == "Push") {
      ll n, m; cin >> n >> m;
      stack.emplace_back(m, n);
      size += n;
      if (size > L) {
        cout << "FULL\n";
        return 0;
      }
    }else if (op == "Pop") {
      ll n; cin >> n;
      size -= n;
      if (size < 0) {
        cout << "EMPTY\n";
        return 0;
      }
      ll cnt = 0;
      while (true) {
        auto [a, k] = stack.back(); stack.pop_back();
        if (cnt + k > n) {
          stack.emplace_back(a, k - (n - cnt));
          break;
        }else if (cnt + k == n) {
          break;
        }else {
          cnt += k;
        }
      }
    }else if (op == "Top") {
      if (size == 0) {
        cout << "EMPTY\n";
        return 0;
      }
      auto [a, k] = stack.back();
      cout << a << "\n";
    }else if (op == "Size") {
      cout << size << "\n";
    }else assert(0);
  }
  cout << "SAFE\n";
  return 0;
}

