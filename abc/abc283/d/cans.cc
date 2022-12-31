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
  vector<char> stack;
  vector<bool> in(26);
  ll N = SIZE(S);
  REP(i, 0, N) {
    if (S[i] == '(') {
      stack.push_back('(');
    }else if (S[i] == ')') {
      while (true) {
        char c = stack.back(); stack.pop_back();
        assert (c != ')');
        if (c == '(') break;
        assert (in[c - 'a']);
        in[c - 'a'] = false;
      }
    }else {
      if (in[S[i] - 'a']) {
        cout << "No\n";
        return 0;
      }
      in[S[i] - 'a'] = true;
      stack.push_back(S[i]);
    }
  }
  cout << "Yes\n";
  return 0;
}

