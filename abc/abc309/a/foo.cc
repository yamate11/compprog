#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
  auto f = [&](auto f, auto g, ll a) -> void {
#pragma GCC diagnostic pop
    if (a == 0) return;
    cout << "f";
    g(f, g, a - 1);
  };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
  auto g = [&](auto f, auto g, ll a) -> void {
#pragma GCC diagnostic pop
    if (a == 0) return;
    cout << "g";
    f(f, g, a - 1);
  };

  f(f, g, 4);
  cout << endl;
  g(f, g, 5);
  cout << endl;
  

  return 0;
}

