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

struct MyComp {
  bool operator()(int a, int b) const { return a > b; }
};

bool f(int a, int b) { return a > b; }

int main() {
  
  auto lf = [](int a, int b) { return a > b; };

  // set xs({0, 1, 2}, greater<>{});
  // set xs({0, 1, 2}, f);
  // set xs({0, 1, 2}, lf);
  set xs({0, 1, 2}, MyComp{});
  xs.insert(3);
  xs.insert(4);
  xs.insert(5);
  for (int x : xs) cout << x << endl;

}
