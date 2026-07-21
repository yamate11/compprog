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
  string S; cin >> S;

  deque<ll> deq;
  bool rev = false;
  REP(i, 0, N) {
    if (rev) deq.push_front(i);
    else deq.push_back(i);
    if (S[i] == 'o') rev = not rev;
  }
  vector<ll> ans;
  if (rev) {
    REPrev(i, N - 1, 0) ans.push_back(deq[i]);
  }else {
    REP(i, 0, N) ans.push_back(deq[i]);
  }
  REPOUT(i, 0, N, ans[i] + 1, " ");
  

  return 0;
}

