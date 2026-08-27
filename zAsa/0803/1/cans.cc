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

  ll N; cin >> N;
  vector<ll> vec;
  REP(i, 0, N) {
    auto prev = move(vec);
    vec = vector<ll>{};
    REP(j, 0, i + 1) {
      if (j == 0) vec.push_back(1);
      else if (j == i) vec.push_back(1);
      else vec.push_back(prev[j - 1] + prev[j]);
    }
    REPOUT(j, 0, i + 1, vec[j], " ");
  }

  return 0;
}

