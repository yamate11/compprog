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

  ll N, M; cin >> N >> M;
  vector<bool> vec(N);
  REP(i, 0, M) {
    ll a; cin >> a; a--;
    vec[a] = true;
  }
  vector<ll> ans;
  vector<ll> stack;
  REP(i, 0, N) {
    if (vec[i]) stack.push_back(i);
    else {
      ans.push_back(i);
      while (not stack.empty()) {
        ll x = stack.back(); stack.pop_back();
        ans.push_back(x);
      }
    }
  }
  REPOUT(i, 0, N, ans[i] + 1, " ");
  return 0;
}

