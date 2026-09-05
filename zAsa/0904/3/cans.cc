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

  string S; cin >> S;
  deque<char> deq;
  bool reversed = false;
  REP(i, 0, ssize(S)) {
    char c = S[i];
    if (c == 'R') reversed = !reversed;
    else if (reversed) {
      if (not deq.empty() and deq.front() == c) deq.pop_front();
      else deq.push_front(c);
    }else {
      if (not deq.empty() and deq.back() == c) deq.pop_back();
      else deq.push_back(c);
    }
  }
  if (reversed) {
    while (not deq.empty()) {
      cout << deq.back();
      deq.pop_back();
    }
  }else {
    while (not deq.empty()) {
      cout << deq.front();
      deq.pop_front();
    }
  }
  cout << "\n";

  return 0;
}

