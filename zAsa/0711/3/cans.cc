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
  bool rev = false;
  deque<char> deq;
  for (char c : S) {
    if (c == 'R') {
      rev = not rev;
    }else {
      if (rev) deq.push_front(c);
      else deq.push_back(c);
    }
  }
  if (rev) reverse(ALL(deq));
  string ans;
  for (char c : deq) {
    if (ssize(ans) > 0 and ans.back() == c) ans.pop_back();
    else ans.push_back(c);
  }
  cout << ans << endl;

  return 0;
}

