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
  // @InpVec(N, A) [ozRo693v]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [ozRo693v]

  unordered_set<ll> ans;

  vector<ll> vec;

  auto f = [&](auto rF, ll i, ll cur) {
    if (i == N) {
      ans.insert(cur);
      return;
    }
    REP(j, 0, ssize(vec)) {
      ll new_cur = cur ^ vec[j] ^ (vec[j] + A[i]);
      vec[j] += A[i];
      rF(rF, i + 1, new_cur);
      vec[j] -= A[i];
    }
    {
      vec.push_back(A[i]);
      rF(rF, i + 1, cur ^ A[i]);
      vec.pop_back();
    }
  };

  f(f, 0, 0);
  cout << ssize(ans) << endl;


  return 0;
}

