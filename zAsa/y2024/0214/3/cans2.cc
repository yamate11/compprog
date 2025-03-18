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
  vector<ll> A{-1};
  REP(i, 0, N) { ll a; cin >> a; A.push_back(a); }
  A.push_back(-1);
  auto f = [&](const auto& V) -> vector<ll> {
    vector<ll> vec;
    vector<ll> st{0};
    REP(i, 1, N + 1) {
      while (V[st.back()] >= V[i]) st.pop_back();
      vec.push_back(i - st.back() - 1);
      st.push_back(i);
    }
    return vec;
  };
  auto vA = f(A);
  auto B = A; reverse(ALL(B));
  auto vB = f(B);
  reverse(ALL(vB));
  ll ans = 0;
  REP(i, 0, N) {
    ans = max(ans, (vA[i] + vB[i] + 1) * A[i + 1]);
  }
  cout << ans << endl;

  return 0;
}

