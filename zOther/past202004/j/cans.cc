#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

using Pair = pair<string, ll>;
Pair doit(string s, ll pos) {
  ll i = pos;
  string res;
  while (i < (ll)s.size()) {
    if (s.at(i) == '(') {
      string recres; ll newPos; tie(recres, newPos) = doit(s, i+1);
      res += recres;
      reverse(recres.begin(), recres.end());
      res += recres;
      i = newPos;
    }else if (s.at(i) == ')') {
      return make_pair(res, i+1);
    }else {
      res += s.at(i);
      i++;
    }
  }
  return make_pair(res, (ll)s.size());
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  string ans; ll dummy; tie(ans, dummy) = doit(S, 0);
  cout << ans << endl;

  return 0;
}

