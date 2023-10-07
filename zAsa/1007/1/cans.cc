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

  auto flip = [&](char c) -> char { return c == '#' ? '.' : '#'; };

  ll N, A, B; cin >> N >> A >> B;
  char c0 = '.';
  REP(i, 0, A * N) {
    if (i > 0 and i % A == 0) c0 = flip(c0);
    char c = c0;
    REP(j, 0, B * N) {
      if (j > 0 and j % B == 0) c = flip(c);
      cout << c;
    }
    cout << "\n";
  }
  return 0;
}

