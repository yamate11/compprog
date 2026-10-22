#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

int main() {
  using pii = pair<int, int>;
  vector<pii> V{{1,1}, {2,2}};
  array<pii, 2> P{pii{1,1}, pii{2,2}};
  array<pii, 2> Q{{1,1}, {2,2}};

  return 0;
}
