#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll N = SIZE(S);

  ll b = false;
  deque<char> deq;
  REP(i, 0, N) {
    if (S[i] == 'R') b = not b;
    else if (b) {
      if (not deq.empty() and deq.front() == S[i]) deq.pop_front();
      else deq.push_front(S[i]);
    }else if (not b) {
      if (not deq.empty() and deq.back() == S[i]) deq.pop_back();
      else deq.push_back(S[i]);
    }
  }
  while (not deq.empty()) {
    if (not b) {
      cout << deq.front();
      deq.pop_front();
    }else {
      cout << deq.back();
      deq.pop_back();
    }
  }
  cout << endl;

  return 0;
}

