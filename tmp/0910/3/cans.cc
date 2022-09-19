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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string s; cin >> s;
  vector<char> stack;
  REP(i, 0, N) {
    stack.push_back(s[i]);
    ll k = stack.size();
    if (k >= 3 and stack[k - 1] == 'x' and stack[k - 2] == 'o' and stack[k - 3] == 'f') {
      stack.pop_back();
      stack.pop_back();
      stack.pop_back();
    }
  }
  cout << stack.size() << endl;

  return 0;
}

