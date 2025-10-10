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

  auto solve = [&]() -> void {
    ll N; cin >> N;

    auto f = [&](const auto& A) -> pair<ll, vector<ll>> {
      vector<ll> ret(N);
      vector<ll> B;
      REP(i, 0, N) {
        ll k = lower_bound(ALL(B), A[i]) - B.begin();
        ret[i] = k;
        if (k == ssize(B)) {
          B.push_back(A[i]);
        }else {
          B[k] = A[i];
        }
      }
      return {ssize(B), move(ret)};
    };

    // @InpVec(N, A) [7eaGUklD]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [7eaGUklD]

    auto tmp1 = f(A);
    auto& [n1, vec1] = tmp1;
    reverse(ALL(A));
    REP(i, 0, N) A[i] = -A[i];
    auto tmp2 = f(A);
    auto& [n2, vec2] = tmp2;
    reverse(ALL(vec2));
    assert(n1 == n2);
    vector<ll> ans;
    REP(i, 0, N) if (vec1[i] + vec2[i] + 1 >= n1) ans.push_back(i);
    cout << ssize(ans) << "\n";
    REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  };

  ll T; cin >> T;
  REP(t, 0, T) solve(); 

  return 0;
}

