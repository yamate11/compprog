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
  // @InpVec(N, H) [2uUveE1Y]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [2uUveE1Y]

  H.push_back(N + 1);
  vector<ll> vec(N);
  vector<ll> stack{N};
  REPrev(i, N - 1, 0) {
    while (true) {
      ll x = stack.back();
      if (H[i] < H[x]) {
        stack.push_back(i);
        vec[i] = x;
        break;
      }else {
        stack.pop_back();
      }
    }
  }
  vector<bool> A(N);
  vector<ll> ans;
  ll cnt = 0;
  REP(i, 0, N) {
    if (A[i]) {
      A[i] = false;
      cnt--;
    }
    ll j = i + 1;
    while (j < N) {
      if (A[j]) break;
      A[j] = true;
      cnt++;
      j = vec[j];
    }
    ans.push_back(cnt);
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

