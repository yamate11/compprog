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

  ll N, M; cin >> N >> M;
  string S; cin >> S;
  vector<ll> ans;
  ll cur = N;
  while (cur > 0) {
    auto func = [&]() -> ll {
      REPrev(i, M, 1) {
        if (cur - i <= 0) return cur;
        else if (S[cur - i] == '0') return i;
      }
      return -1;
    };
    ll z = func();
    if (z < 0) {
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(z);
    cur -= z;
  }
  reverse(ALL(ans));
  REPOUT(i, 0, SIZE(ans), ans[i], " ");

  return 0;
}

