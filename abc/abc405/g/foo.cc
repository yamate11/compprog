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

int main() {
  auto f_one = [](auto rF, ll x) -> bool {
    return rF(rF, x - 1);
  };
  auto f_two = [&f_one](auto rF, ll x) -> bool {
    return f_one(rF, x - 1);
  };
  auto f_zero = [&f_two](auto rF, ll x) -> bool {
    if (x == 0) return true;
    else if (x == 1) return false;
    else if (x == 2) return false;
    return f_two(rF, x - 1);
  };
  cout << f_zero(f_zero, 9) << endl;
  cout << f_one(f_zero, 4) << endl;
  cout << f_two(f_zero, 11) << endl;

  auto factorial = [](this auto self, ll x) {
    if (x == 0) return 1;
    return x * self(x - 1);
  };
  cout << factorial(4) << endl;

}
