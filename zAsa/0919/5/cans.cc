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
    ll N = ssize(S);
    ll K; cin >> K;
    if (K % 2 != 0) return "First";
    vector<ll> A(N, 0LL);
    vector<ll> stack;
    REP(i, 0, N) {
      if (S[i] == '(') stack.push_back(i);
      else {
        if (stack.empty()) return "First";
        ll j = stack.back(); stack.pop_back();
        A[j] = i;
        A[i] = j;
      }
    }
    if (not stack.empty()) return "First";
    ll p = 0, q = N - 1;
    while (p < q and A[p] == q) { p++; q--; }
    if (q <= p) return "Second";
    if (A[p] == p + 1 and A[q] == q - 1) {
      ll x = p;
      for (; x < q and A[x] == x + 1; x += 2);
      ll y = q;
      for (; y > p and A[y] == y - 1; y -= 2);
      if (y <= x) return "Second";
      if (x + K < q) return "First";
      if (p + K < y) return "First";
      return "Second";
    }else {
      if (p + K < q) return "First";
      return "Second";
    }
    
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

