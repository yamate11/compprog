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

  auto solve = [&]() -> string {
    string S; cin >> S;
    ll K; cin >> K;
    if (K % 2 != 0) return "First";
    ll N = ssize(S);
    vector<ll> A(N);
    vector<ll> stack;
    REP(i, 0, N) {
      if (S[i] == '(') stack.push_back(i);
      else {
        if (stack.empty()) return "First";
        ll x = stack.back(); stack.pop_back();
        A[x] = i;
        A[i] = x;
      }
    }
    if (not stack.empty()) return "First";
    ll p = 0, q = N - 1;
    while (q - p + 1 > K and A[p] == q) { p++; q--; }
    if (q - p + 1 == K) return "Second";
    ll p_save = p, q_save = q;
    while (p < q and A[p] == p + 1) p += 2;
    if (p >= q) return "Second";
    while (p < q and A[q] == q - 1) q -= 2;
    if (q_save - p + 1 > K or q - p_save + 1 > K) return "First";
    return "Second";
  };

  ll T; cin >> T;
  REP(t, 0, T) {
    cout << solve() << "\n";
  }
      

  return 0;
}

