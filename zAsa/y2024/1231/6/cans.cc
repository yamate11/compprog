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
  vector cur(3, 0LL);
  REP(i, 0, 3) cin >> cur[i];
  vector<ll> ans;
  // @InpVec(N, S, type=string) [RRSUaj8x]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [RRSUaj8x]
  REP(i, 0, N) {
    string s = S[i];
    ll p = s[0] - 'A';
    ll q = s[1] - 'A';
    if (cur[p] == 0 and cur[q] == 0) {
      cout << "No\n";
      return 0;
    }

    auto op = [&](ll i0, ll i1) -> void {
      cur[i0]++;
      cur[i1]--;
      ans.push_back(i0);
    };

    if (cur[p] == 0) op(p, q);
    else if (cur[q] == 0) op(q, p);
    else if (i == N - 1) op(p, q);
    else {
      ll p1 = S[i + 1][0] - 'A';
      ll p2 = S[i + 1][1] - 'A';
      if (p == p1 or p == p2) op(p, q);
      else op(q, p);
    }
  }
  cout << "Yes\n";
  REPOUT(i, 0, N, (char)('A' + ans[i]), "\n");

  return 0;
}

