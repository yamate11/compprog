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
  using sta = tuple<ll, ll, ll>;
  vector<sta> STI;
  REP(i, 0, N) {
    ll s, t; cin >> s >> t;
    STI.emplace_back(s, t, i);
  }
  sort(ALL(STI));

  vector<ll> ans;
  vector<ll> tmp;
  ll cur = 0;
  for (auto [s, t, i] : STI) {
    if (t < cur) {
      cout << "No\n";
      return 0;
    }
    if (t < s) {
      while (not tmp.empty()) {
        ans.push_back(tmp.back());
        tmp.pop_back();
      }
      ans.push_back(i);
      cur = t;
    }else {
      tmp.push_back(i);
      cur = t;
    }
  }
  while (not tmp.empty()) {
    ans.push_back(tmp.back());
    tmp.pop_back();
  }
  cout << "Yes\n";
  REPOUT(i, 0, N, ans[i] + 1, " ");

  return 0;
}

