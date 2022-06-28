#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string s; cin >> s;
  vector<char> stack;
  for (char c : s) {
    ll n = SIZE(stack);
    if (n >= 2 and stack[n - 2] == 'f' and stack[n - 1] == 'o' and c == 'x') {
      stack.pop_back();
      stack.pop_back();
    }else {
      stack.push_back(c);
    }
  }
  cout << SIZE(stack) << endl;
  return 0;
}

